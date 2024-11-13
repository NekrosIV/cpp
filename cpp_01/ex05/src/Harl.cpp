/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:20:51 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/13 17:59:28 by kasingh          ###   ########.fr       */
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
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*actions[])() = {&Harl::debug, &Harl::info, &Harl::warning,
		&Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*actions[i])();
			return ;
		}
	}
	std::cout << BRED << "Level not found" << RESET << std::endl;
}