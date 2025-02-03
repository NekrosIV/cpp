/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:52:17 by kasingh           #+#    #+#             */
/*   Updated: 2025/01/31 12:27:08 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog created!" << std::endl;
}
Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << "Dog copied!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Dog assigned!" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destroyed!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}