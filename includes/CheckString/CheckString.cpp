/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckString.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:52:05 by tcardair          #+#    #+#             */
/*   Updated: 2026/01/08 17:25:24 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CheckString.hpp"
#include "../../cppMaker.main.hpp"

// Get an index from a std::string;
// Check if the index contained in str is whithin size.
// From 0 to size -1
// Return values:
// 	success:
//		index;
//	error:
//		-1;
int getIndex(int &size, std::string &str)
{
	int index = -1;

	if (str.empty())
		return (-1);
	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (-1);
	}
	std::stringstream ss(str);
	if (!(ss >> index))
		return (-1);
	if (index < 0 || index > size)
		return (-1);
	return (index);
}

// Check if the string is alpha.
bool checkString(std::string const &str)
{
	if (str.empty())
		return (false);
	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (!std::isalpha(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

// Check if str is a number.
bool checkNumber(std::string const &str)
{
	if (str.empty() || str.length() != 10)
		return (false);
	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}