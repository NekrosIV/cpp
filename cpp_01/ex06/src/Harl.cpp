/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:20:51 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/13 18:01:55 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "color.h"

void Harl::debug(void)
{
	std::cout << BGREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << RESET << std::endl;
}
void Harl::info(void)
{
	std::cout << BBLUE
				<< "I cannot believe adding extra bacon costs more money. "
					"You didn’t put enough bacon in my burger ! If you did,I wouldn’t be asking for more !"
				<< RESET << std::endl;
}

void Harl::warning(void)
{
	std::cout << BYELLOW
				<< "I think I deserve to have some extra bacon for free. "
					"I’ve been coming for years whereas you started working here since last month"
				<< RESET << std::endl;
}
void Harl::error(void)
{
	std::cout << BRED << "This is unacceptable ! I want to speak to the manager now." << RESET << std::endl;
}
void Harl::complain(std::string level)
{
	int i;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			break ;
	}
	switch (i)
	{
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break ;
	default:
		std::cout << BRED << "Level not found" << RESET << std::endl;
		break ;
	}
}
