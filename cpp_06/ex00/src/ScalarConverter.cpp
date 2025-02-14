/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:47:10 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/14 14:31:57 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}
bool ScalarConverter::isChar(const std::string &input)
{
	return (input.length() == 1 && !std::isdigit(input[0]));
}
bool ScalarConverter::isFloat(const std::string &input)
{
	return ((input.find('f') != std::string::npos || input.find('F') != std::string::npos)&& input.find('.') != std::string::npos && isDouble(input.substr(0, input.length() - 1)));
}
bool ScalarConverter::isDouble(const std::string &input)
{
	char	*end;

	std::strtod(input.c_str(), &end);
	return (end[0] == '\0');
}

void ScalarConverter::printChar(double value)
{
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || std::isnan(value))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
	if (std::isnan(value) || std::isinf(value))
		std::cout << "float: " << value << "f" << std::endl;
	else
	{
		std::cout << "float: " << static_cast<float>(value);
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double value)
{
	if (std::isnan(value) || std::isinf(value))
		std::cout << "double: " << value << std::endl;
	else
	{
		std::cout << "double: " << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void ScalarConverter::convert(const std::string &input)
{
	std::cout << "Received input: " << input << std::endl;

    if (isChar(input)) {
        char c = input[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    
    char* endPtr;
    double value = std::strtod(input.c_str(), &endPtr);
    if (*endPtr != '\0' && !isFloat(input)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
	
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}