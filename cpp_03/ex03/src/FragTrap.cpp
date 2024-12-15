/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:01:59 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/14 16:19:14 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "color.h"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	hitPoint = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << BGREEN << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	hitPoint = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << BGREEN << "FragTrap parameterized constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << BYELLOW << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << BYELLOW << "FragTrap copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << BCYAN << "FragTrap " << name << " is asking for a high five! ✋" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout  << BRED << "FragTrap destructor called" << RESET << std::endl;
}