/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:00:12 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/14 15:42:54 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <iostream>
#include "ScavTrap.hpp"

int main() {
    std::cout << "Creating ScavTrap..." << std::endl;
    ScavTrap scav("Guardian");

    std::cout << "\nTesting ScavTrap attacks..." << std::endl;
    scav.attack("Target1");

    std::cout << "\nTesting ScavTrap takes damage..." << std::endl;
    scav.takeDamage(20);

    std::cout << "\nTesting ScavTrap repairs itself..." << std::endl;
    scav.beRepaired(15);

    std::cout << "\nTesting ScavTrap guard mode..." << std::endl;
    scav.guardGate();

    std::cout << "\nEnd of tests. Destructors will be called automatically." << std::endl;
    return 0;
}
