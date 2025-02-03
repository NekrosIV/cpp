/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:12:45 by kasingh           #+#    #+#             */
/*   Updated: 2025/01/25 15:23:55 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal created!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &typeOfWrongAnimal) : type(typeOfWrongAnimal) {
    std::cout << "WrongAnimal of type " << type << " created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
    std::cout << "WrongAnimal copied!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "WrongAnimal assigned!" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed!" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes a generic sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}