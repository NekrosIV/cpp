/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:42:55 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/13 16:11:23 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "color.h"
#include <cstdio>
#include <iostream>
#include <limits>
#include <string>

std::string Contact::getFirstName() const
{
	return (firstName);
}

std::string Contact::getLastName() const
{
	return (lastName);
}

std::string Contact::getNickName() const
{
	return (nickName);
}

void Contact::print() const
{
	std::cout << BCYAN << "First Name: " << RESET << firstName << std::endl;
	std::cout << BCYAN << "Last Name: " << RESET << lastName << std::endl;
	std::cout << BCYAN << "Nickname: " << RESET << nickName << std::endl;
	std::cout << BCYAN << "Phone Number: " << RESET << phoneNumber << std::endl;
	std::cout << BCYAN << "Darkest Secret: " << RESET << darkestSecret << std::endl;
}
static bool	isAlpha(std::string input)
{
	if (input.empty())
		return (false);
	for (std::string::iterator it = input.begin(); it != input.end(); ++it)
	{
		if (!std::isalpha(*it))
			return (false);
	}
	return (true);
}

static bool	isDigits(std::string input)
{
	if (input.empty())
		return (false);
	for (std::string::iterator it = input.begin(); it != input.end(); ++it)
	{
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

static bool	isAlphaNum(std::string input)
{
	if (input.empty())
		return (false);
	for (std::string::iterator it = input.begin(); it != input.end(); ++it)
	{
		if (!std::isalpha(*it) && !std::isdigit(*it) && *it != ' ')
			return (false);
	}
	return (true);
}

static bool	check_eof(void)
{
	if (std::cin.eof())
	{
		std::cin.clear();
		clearerr(stdin);
		std::cout << BRED << "\n\e[1A\e[KFail to creat a new contact" << RESET << std::endl;
		return (true);
	}
	return (false);
}

bool Contact::add()
{
	while (true)
	{
		std::cout << BMAGENTA << "Enter first name (letters only): " << RESET;
		std::getline(std::cin >> std::ws, firstName);
		if (check_eof())
			return (false);
		if (isAlpha(firstName))
			break ;
		std::cout << BRED << "Error: First name must contain only letters. Please try again." << RESET << std::endl;
	}
	while (true)
	{
		std::cout << BMAGENTA << "Enter last name (letters only): " << RESET;
		std::getline(std::cin >> std::ws, lastName);
		if (check_eof())
			return (false);
		if (isAlpha(lastName))
			break ;
		std::cout << BRED << "Error: Last name must contain only letters. Please try again." << RESET << std::endl;
	}
	while (true)
	{
		std::cout << BMAGENTA << "Enter nickname (AlphaNumeric only): " << RESET;
		std::getline(std::cin >> std::ws, nickName);
		if (check_eof())
			return (false);
		if (isAlphaNum(nickName))
			break ;
		std::cout << BRED << "Error: nick name must contain only letters or digit. Please try again." << RESET << std::endl;
	}
	while (true)
	{
		std::cout << BMAGENTA << "Enter phone number (digits only): " << RESET;
		if (check_eof())
			return (false);
		std::getline(std::cin >> std::ws, phoneNumber);
		if (isDigits(phoneNumber))
			break ;
		std::cout << BRED << "Error: Phone number must contain only digits. Please try again." << RESET << std::endl;
	}
	while (true)
	{
		std::cout << BMAGENTA << "Enter darkest secret (AlphaNumeric only): " << RESET;
		std::getline(std::cin >> std::ws, darkestSecret);
		if (check_eof())
			return (false);
		if (isAlphaNum(darkestSecret))
			break ;
		std::cout << BRED << "Error: darkest must contain only letters or digit. Please try again." << RESET << std::endl;
	}
	return (true);
}
