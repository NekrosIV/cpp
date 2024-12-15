/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:27:59 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/13 16:06:03 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "color.h"

int main() 
{
    std::cout << "Creating ClapTrap: Bob" << RESET << std::endl;
    ClapTrap bob("Bob");

    std::cout << "\nBob attempts to attack!" << RESET << std::endl;
    bob.attack("Target1");

    std::cout << "\nBob takes damage!" << RESET << std::endl;
    bob.takeDamage(5);

    std::cout << "\nBob repairs himself!" << RESET << std::endl;
    bob.beRepaired(7);

    std::cout << "\nBob attacks until out of energy!" << RESET << std::endl;
    for (int i = 0; i < 12; ++i) {
        bob.attack("Target2");
    }

    std::cout << "\nBob takes heavy damage!" << RESET << std::endl;
    bob.takeDamage(50);

    std::cout << "\nBob tries to repair himself while dead!" << RESET << std::endl;
    bob.beRepaired(10);

    std::cout << "\nClapTrap Tests Completed!" << RESET << std::endl;
    return 0;
}