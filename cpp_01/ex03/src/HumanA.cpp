/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:35:23 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/09 14:59:19 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &type) : name(name), type(type)
{
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << type.getType() << std::endl;
}

HumanA::~HumanA()
{
}