/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:53:01 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/04 17:25:59 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "color.h"
#include <iostream>

int	main(void)
{
	PhoneBook	phoneBook;

	std::string line;
	while (true)
	{
		std::cout << BWHITE <<"Enter a command: " << RESET;
		std::getline(std::cin, line);
		if (line == "ADD")
			phoneBook.addContact();
		else if (line == "SEARCH")
			phoneBook.displayContacts();
		else if (line == "EXIT" || std::cin.eof())
			break ;
		else
			std::cout << BRED << "Command not found. Please try again." << std::endl;
	}
	return (0);
}
