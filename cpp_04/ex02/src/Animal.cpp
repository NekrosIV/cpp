/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:12:45 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/01 15:51:01 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal") {
    std::cout << "Animal created!" << std::endl;
}

Animal::Animal(const std::string &typeOfAnimal) : type(typeOfAnimal) {
    std::cout << "Animal of type " << type << " created!" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copied!" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Animal assigned!" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed!" << std::endl;
}
