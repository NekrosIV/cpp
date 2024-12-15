/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:27:59 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/14 16:20:00 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main() {
    std::cout << "Creating FragTrap..." << std::endl;
    FragTrap frag("HighFiver");

    std::cout << "\nTesting FragTrap attacks..." << std::endl;
    frag.attack("Target1");

    std::cout << "\nTesting FragTrap takes damage..." << std::endl;
    frag.takeDamage(30);

    std::cout << "\nTesting FragTrap repairs itself..." << std::endl;
    frag.beRepaired(50);

    std::cout << "\nTesting FragTrap high five..." << std::endl;
    frag.highFivesGuys();

    std::cout << "\nEnd of tests. Destructors will be called automatically." << std::endl;
}