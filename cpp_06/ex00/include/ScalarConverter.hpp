/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:04:20 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/14 14:27:34 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter
{
  private:
	ScalarConverter();
	~ScalarConverter();

	static bool isChar(const std::string &input);
	static bool isFloat(const std::string &input);
	static bool isDouble(const std::string &input);

	static void printChar(double value);
	static void printInt(double value);
	static void printFloat(double value);
	static void printDouble(double value);

  public:
	static void convert(const std::string &input);
};
