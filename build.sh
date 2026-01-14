#!/bin/sh

# Build and install the 'cppMaker' program in a simple, portable way.
# - Compiles cppMaker using the Makefile
# - Installs it to ~/.local/bin by default (or a dir you pass as $1)
# - Creates a 'cppm' alias/symlink for easy access
# - Ensures that directory is on PATH for future shells

set -e

# Always run relative to this script's directory
cd -- "$(dirname "$0")"

# Clean and build using the Makefile
echo "Building cppMaker..."
make re

# Choose install directory (override by passing one, e.g. /usr/local/bin)
PREFIX="${1:-$HOME/.local/bin}"
mkdir -p "$PREFIX"

# Install the binary (prefer 'install', fallback to cp + chmod)
if command -v install >/dev/null 2>&1; then
  install -m 755 cppMaker "$PREFIX/cppMaker"
else
  cp cppMaker "$PREFIX/cppMaker"
  chmod 755 "$PREFIX/cppMaker"
fi
echo "Installed to: $PREFIX/cppMaker"

# Create 'cppm' symlink/alias for convenience
if command -v install >/dev/null 2>&1; then
  ln -sf "$PREFIX/cppMaker" "$PREFIX/cppm"
else
  ln -s "$PREFIX/cppMaker" "$PREFIX/cppm" 2>/dev/null || cp "$PREFIX/cppMaker" "$PREFIX/cppm"
fi
echo "Created shortcut: $PREFIX/cppm"

# If not already on PATH, append to ~/.profile so future shells can find it
case ":$PATH:" in
  *":$PREFIX:"*) ;;  # already present
  *)
    printf '\n# Added by cppMaker build.sh\nexport PATH="%s:$PATH"\n' "$PREFIX" >> "$HOME/.profile"
    echo "Added $PREFIX to PATH in ~/.profile"
    echo "Open a new terminal or run: . ~/.profile"
    ;;
esac
echo
echo "Done. You can now run: cppm (or cppMaker)"