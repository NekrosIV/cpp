/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:02:45 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/03 17:22:50 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice materia created!" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
	std::cout << "Ice materia copied!" << std::endl;
}
Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	std::cout << "Ice materia assigned!" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice materia destroyed!" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}