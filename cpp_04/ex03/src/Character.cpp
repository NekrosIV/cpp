/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:13:48 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/07 14:40:44 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "color.h"

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character " << name << " created!" << std::endl;
}
Character::Character(Character const &other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = 0;
	}
}

Character &Character::operator=(Character const &other)
{

	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = 0;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete inventory[i];
	std::cout << "Character " << name << " destroyed!" << std::endl;
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << BRED <<"Could not equip item, inexistant type" << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout << name << " equipped " << m->getType() << "!" << std::endl;
			return ;
		}
		if (inventory[i] == m)
        {
            std::cout << BRED << name << " already has this materia equipped!"<< RESET << std::endl;
            return ;
        }
	}
	std::cout << BYELLOW << name << " has no space to equip " << m->getType() << "!" << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		std::cout << BYELLOW << name << " unequipped " << inventory[idx]->getType() << "!" << RESET << std::endl;
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}