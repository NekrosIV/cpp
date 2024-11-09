/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:59:46 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/09 15:07:08 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), type(NULL)
{
}

void HumanB::setWeapon(Weapon &type)
{
	this->type = &type;
}

void HumanB::attack(void)
{
	if (type)
		std::cout << name << " attacks with their " << type->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with." << std::endl;
}

HumanB::~HumanB()
{
}