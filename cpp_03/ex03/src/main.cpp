/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:27:59 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/15 15:31:47 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main() {
    std::cout << "Creating DiamondTrap..." << std::endl;
    DiamondTrap diamond("Shiny");

    std::cout << "\nTesting DiamondTrap attacks..." << std::endl;
    diamond.attack("Target1");

    std::cout << "\nTesting DiamondTrap whoAmI..." << std::endl;
    diamond.whoAmI();

    std::cout << "\nTesting DiamondTrap takes damage and repairs..." << std::endl;
    diamond.takeDamage(50);
    diamond.beRepaired(30);

    std::cout << "\nEnd of tests. Destructors will be called automatically." << std::endl;
    return 0;
}