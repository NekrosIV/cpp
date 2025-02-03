/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:52:17 by kasingh           #+#    #+#             */
/*   Updated: 2025/01/31 12:26:23 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat created!" << std::endl;
}
Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << "Cat copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Cat assigned!" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destroyed!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau! Miau!" << std::endl;
}