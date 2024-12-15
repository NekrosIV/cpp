/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:26:30 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/15 15:32:31 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "color.h"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap()
{
	name = "Default";
	hitPoint = FragTrap::hitPoint;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << BGREEN << "DiamondTrap default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name
	+ "_clap_name"), FragTrap(), ScavTrap()
{
	this->name = name;
	hitPoint = FragTrap::hitPoint;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << BGREEN << "DiamondTrap parameterized constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	FragTrap(other), ScavTrap(other)
{
	*this = other;
	std::cout << BYELLOW << "DiamondTrap copy constructor called" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		name = other.name;
	}
	std::cout << BYELLOW << "DiamondTrap copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << BCYAN << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BRED << "DiamondTrap destructor called" << RESET << std::endl;
}
