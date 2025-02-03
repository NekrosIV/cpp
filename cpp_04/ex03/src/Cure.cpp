/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:25:07 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/03 18:05:36 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure materia created!" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
	std::cout << "Cure materia copied!" << std::endl;
}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	std::cout << "Cure materia assigned!" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure materia destroyed!" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
