/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:53:01 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/09 14:00:06 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "color.h"
#include <iostream>

void print_available_cmd()
{
    std::cout << BRED << "╔═════════════════════════════╗" << RESET << std::endl;
    std::cout << BRED << "║      " << BYELLOW << "Available Commands" << BRED << "     ║" << RESET << std::endl;
    std::cout << BRED << "╠═════════════════════════════╣" << RESET << std::endl;
    std::cout << BRED << "║ " << BGREEN << "ADD" << BRED << "    - Add a contact      ║" << RESET << std::endl;
    std::cout << BRED << "║ " << BGREEN << "SEARCH" << BRED << " - Search contacts    ║" << RESET << std::endl;
    std::cout << BRED << "║ " << BGREEN << "EXIT" << BRED << "   - Exit the program   ║" << RESET << std::endl;
    std::cout << BRED << "╚═════════════════════════════╝" << RESET << std::endl;
}

int	main(void)
{
	PhoneBook	phoneBook;

	std::string line;
	print_available_cmd();
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
