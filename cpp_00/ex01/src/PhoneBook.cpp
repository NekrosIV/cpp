/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:17:13 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/04 17:33:23 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <cstdio>
#include "color.h"
#include <sstream>

PhoneBook::PhoneBook() : contactCount(0)
{
}
void PhoneBook::addContact()
{
	if (contacts[contactCount % 8].add())
		contactCount++;
}

std::string PhoneBook::formatField(std::string field) const
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void PhoneBook::displayContacts() const {
	std::string b_color;
	std::string color;
    int indexNum;
    std::string index;
	
    std::cout << ON_LIGHT_GRAY << BBLACK << std::setw(10) << "Index" << " | " 
				<< ON_LIGHT_GRAY << BBLACK << std::setw(10) << "First Name"<< " | " 
				<< ON_LIGHT_GRAY << BBLACK << std::setw(10) << "Last Name"<< " | " 
				<< ON_LIGHT_GRAY << BBLACK << std::setw(10) << "Nickname" << RESET << std::endl;
			  
    int maxContacts = (contactCount < 8) ? contactCount : 8;
	
    for (int i = 0; i < maxContacts; i++) {
		if(i % 2 == 0)
		{
			b_color = ON_DARK_GRAY;
			color = BWHITE;
		}
		else
		{
			b_color = ON_LIGHT_GRAY;
			color = BBLACK;	
		}
			
        std::cout << b_color << color << std::setw(10) << i + 1 << " | "
                  << b_color << color << std::setw(10) << formatField(contacts[i].getFirstName()) << " | "
                  << b_color << color << std::setw(10) << formatField(contacts[i].getLastName()) << " | "
                  << b_color << color << std::setw(10) << formatField(contacts[i].getNickName()) << RESET << std::endl;
    }

    std::cout << BBLUE <<"Enter the index of the contact to display in detail:" << RESET;
    std::getline(std::cin, index);
    if (std::cin.eof()) {
        std::cin.clear();
		clearerr(stdin);
        std::cout << "\n\e[1A\e[K"<< BRED <<"Fail to display in detail" << RESET << std::endl;
		return ;
    }
    std::istringstream iss(index);
    if (!(iss >> indexNum) || indexNum < 1 || indexNum > maxContacts) 
        std::cout << BRED <<"Invalid index."<< RESET << std::endl;
    else 
        contacts[indexNum - 1].print();
}
