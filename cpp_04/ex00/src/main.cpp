/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:27:59 by kasingh           #+#    #+#             */
/*   Updated: 2025/01/31 12:32:40 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "color.h"
#include <iostream>

// int	main(void)
// {
// 	const Animal	*meta = new Animal();
// 	const Animal	*j = new Dog();
// 	const WrongAnimal	*i = new WrongCat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); // will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
//     delete	meta;
// 	delete	j;
// 	delete	i;
// 	return (0);
// }

int main() {
    std::cout << BYELLOW << "==== START OF TESTS ====" << RESET << std::endl;

    // Test object creation
    std::cout << BGREEN << "[TEST] Object creation" << RESET << std::endl;
    const Animal* genericAnimal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    // Test types
    std::cout << BCYAN << "[TEST] Type verification" << RESET << std::endl;
    std::cout << BLUE << "Type of genericAnimal: " << GREEN  << genericAnimal->getType() << RESET << std::endl;
    std::cout << BLUE << "Type of dog: " << GREEN  << dog->getType() << RESET << std::endl;
    std::cout << BLUE << "Type of cat: " << GREEN  << cat->getType() << RESET << std::endl;

    // Test sounds
    std::cout << BMAGENTA << "[TEST] Animal sounds" << RESET << std::endl;
    std::cout << BLUE << "Sound of genericAnimal: " << YELLOW;
    genericAnimal->makeSound();
    std::cout << RESET;
    std::cout << BLUE << "Sound of dog: " << YELLOW;
    dog->makeSound();
    std::cout << RESET;
    std::cout << BLUE << "Sound of cat: " << YELLOW;
    cat->makeSound();
    std::cout << RESET;

    // Cleanup memory
    std::cout << BRED << "[TEST] Object destruction" << RESET << std::endl;
    delete genericAnimal;
    delete dog;
    delete cat;

    // Tests with an animal array
    std::cout << BYELLOW << "[TEST] Polymorphic animal array" << RESET << std::endl;
    const Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; ++i) {
        std::cout << BLUE << "Animal " << i << " (type: " << GREEN << animals[i]->getType() << BLUE << "): " << YELLOW;
        animals[i]->makeSound();
        std::cout << RESET;
    }

    // Cleanup animals in the array
    std::cout << BRED << "[TEST] Destruction of animals in the array" << RESET << std::endl;
    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    std::cout << BYELLOW << "==== END OF TESTS ====" << RESET << std::endl;

    return (0);
}