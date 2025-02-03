/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:51:56 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/03 18:06:46 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria of type " << type << " created!" << std::endl;
}

AMateria::AMateria(AMateria const &other) : type(other.type)
{
	std::cout << "Materia copied!" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Materia assigned!" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Materia destroyed!" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (type);
}
