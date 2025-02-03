/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:27:59 by kasingh           #+#    #+#             */
/*   Updated: 2025/01/31 14:48:26 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "color.h"
#include <iostream>


int main() {
    std::cout << BYELLOW << "==== START OF NORMAL TESTS ====" << RESET << std::endl;

    // Create and populate an array of Animal objects
    std::cout << BGREEN << "[TEST] Creating an array of Animals" << RESET << std::endl;
    const int size = 4;
    const Animal* animals[size];

    for (int i = 0; i < size / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i) {
        animals[i] = new Cat();
    }

    // Cleanup memory
    std::cout << BRED << "[TEST] Deleting animals in the array" << RESET << std::endl;
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }

    std::cout << BYELLOW << "==== END OF NORMAL TESTS ====" << RESET << std::endl;
    
    std::cout << BYELLOW << "==== START OF BRAIN TESTS ====" << RESET << std::endl;

    // Brain tests
    std::cout << BMAGENTA << "[TEST] Brain memory management" << RESET << std::endl;
    Dog originalDog;
    originalDog.setIdea(0, "I love bones!");
    Dog copiedDog(originalDog);
    std::cout << BLUE << "Original Dog Idea: " << GREEN << originalDog.getIdea(0) << RESET << std::endl;
    std::cout << BLUE << "Copied Dog Idea: " << GREEN << copiedDog.getIdea(0) << RESET << std::endl;

    copiedDog.setIdea(0, "I prefer toys!");
    std::cout << BLUE << "After modifying copied dog: " << RESET << std::endl;
    std::cout << "Original Dog Idea: " << GREEN << originalDog.getIdea(0) << RESET << std::endl;
    std::cout << "Copied Dog Idea: " << GREEN << copiedDog.getIdea(0) << RESET << std::endl;

    std::cout << BRED << "CALL DESTRUCTOR" << RESET << std::endl;

    return 0;
}
