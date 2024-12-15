/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:24:54 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/14 15:40:27 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include "color.h"

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoint = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << BGREEN << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	hitPoint = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << BGREEN << "ScavTrap parameterized constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << BYELLOW << "ScavTrap copy constructor called" << RESET << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << BYELLOW << "ScavTrap copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string &target) {
    if (!hitPoint) {
        std::cout << BRED << "ScavTrap " << name << " cannot attack due to lack of health!" << RESET << std::endl;
    } else if (!energyPoints) {
        std::cout << BYELLOW << "ScavTrap " << name << " cannot attack due to lack of energy!" << RESET << std::endl;
    } else {
        energyPoints--;
        std::cout << BBLUE << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage
                  << " points of damage!" << RESET << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << BYELLOW << "ScavTrap " << name << " is now in Gatekeeper mode!" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BRED <<"ScavTrap destructor called" << RESET <<std::endl;
}