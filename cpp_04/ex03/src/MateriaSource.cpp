/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:17:19 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/05 15:19:06 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>
#include "color.h"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materias[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = 0;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete materias[i];
			if (other.materias[i])
				materias[i] = other.materias[i]->clone();
			else
				materias[i] = 0;
		}
	}
    return(*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete materias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!materias[i])
        {
            materias[i] = m;
            return;
        }
    }
    std::cout << BRED << "MateriaSource is full, cannot learn more materias!" << RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    std::cout  << BRED << "MateriaSource does not have this materia type!" << RESET << std::endl;
    return NULL;
}
