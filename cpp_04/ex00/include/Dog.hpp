/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:26:33 by kasingh           #+#    #+#             */
/*   Updated: 2025/01/25 16:16:15 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
  public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();

	void makeSound() const;
};
