/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:31:00 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/07 13:43:39 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string intialeType) : type(intialeType)
{
}

void Weapon::setType(std::string value)
{
	type = value;
}

const std::string &Weapon::getType() const
{
	return (type);
}

Weapon::~Weapon()
{
}