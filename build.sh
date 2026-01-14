#!/bin/sh

# Build and install the 'cppMaker' program with all its dependencies.  
# - Compiles cppMaker using the Makefile
# - Installs it to ~/. local/share/cppMaker with all resources
# - Creates a wrapper script in ~/.local/bin for easy access as 'cppm'
# - Ensures that directory is on PATH for future shells

set -e

# Always run relative to this script's directory
cd -- "$(dirname "$0")"

# Clean and build using the Makefile
echo "Building cppMaker..."
make re

# Installation directories
BIN_DIR="${1:-$HOME/.local/bin}"
INSTALL_DIR="$HOME/.local/share/cppMaker"

mkdir -p "$BIN_DIR"
mkdir -p "$INSTALL_DIR"

# Install the program and all its resources
echo "Installing cppMaker to:  $INSTALL_DIR"
cp cppMaker "$INSTALL_DIR/cppMaker"
chmod 755 "$INSTALL_DIR/cppMaker"

# Copy templates and other necessary files/directories
if [ -d "templates" ]; then
  cp -r templates "$INSTALL_DIR/"
  echo "Copied templates directory"
fi

# You may need to copy other directories too, uncomment if needed: 
# if [ -d "includes" ]; then
#   cp -r includes "$INSTALL_DIR/"
# fi

# Create wrapper script that sets CPPMAKER_DIR but stays in current directory
cat > "$BIN_DIR/cppm" << 'EOF'
#!/bin/sh
# Wrapper script for cppMaker
# Sets CPPMAKER_DIR so the program can find templates
# but executes in the user's current directory
export CPPMAKER_DIR="$HOME/.local/share/cppMaker"
exec "$CPPMAKER_DIR/cppMaker" "$@"
EOF

chmod 755 "$BIN_DIR/cppm"
echo "Created wrapper script: $BIN_DIR/cppm"

# If not already on PATH, append to ~/. profile so future shells can find it
case ":$PATH:" in
  *":$BIN_DIR:"*) ;;  # already present
  *)
    printf '\n# Added by cppMaker build.sh\nexport PATH="%s:$PATH"\n' "$BIN_DIR" >> "$HOME/.profile"
    echo "Added $BIN_DIR to PATH in ~/.profile"
    echo "Open a new terminal or run: .  ~/.profile"
    ;;
esac

echo "Done. You can now run: cppm"
