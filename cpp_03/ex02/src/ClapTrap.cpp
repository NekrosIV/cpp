/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:51:14 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/15 14:45:30 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Default"), hitPoint(10), energyPoints(10), attackDamage(0) {
    std::cout << BGREEN << "ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoints(10), attackDamage(0) {
    std::cout << BGREEN << "ClapTrap parameterized constructor called" RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << BYELLOW << "ClapTrap copy constructor called"  RESET << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << BYELLOW << "ClapTrap copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        name = other.getName();
        hitPoint = other.getHitPoint();
        energyPoints = other.getEnergyPoint();
        attackDamage = other.getAttackDamage();
    }
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (!hitPoint) {
        std::cout << BRED << "ClapTrap " << name << " cannot attack due to lack of health!" << RESET << std::endl;
    } else if (!energyPoints) {
        std::cout << BYELLOW << "ClapTrap " << name << " cannot attack due to lack of energy!" << RESET << std::endl;
    } else {
        energyPoints--;
        std::cout << BBLUE << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage
                  << " points of damage!" << RESET << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!hitPoint) {
        std::cout << BRED << "ClapTrap " << name << " is already dead and cannot take more damage!" << RESET << std::endl;
        return;
    }
    if (hitPoint <= amount) {
        hitPoint = 0;
        std::cout << BRED << "ClapTrap " << name << " took " << amount << " points of damage and is now dead!" << RESET
                  << std::endl;
    } else {
        hitPoint -= amount;
        std::cout << BRED << "ClapTrap " << name << " took " << amount << " points of damage and has " << hitPoint
                  << " hit points left!" << RESET << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!hitPoint) {
        std::cout << BRED << "ClapTrap " << name << " is dead and cannot be repaired!" << RESET << std::endl;
        return;
    }
    if (!energyPoints) {
        std::cout << BYELLOW << "ClapTrap " << name << " has no energy left and cannot be repaired!" << RESET
                  << std::endl;
        return;
    }
    energyPoints--;
    hitPoint += amount;
    std::cout << BGREEN << "ClapTrap " << name << " repairs itself for " << amount << " hit points, now at " << hitPoint
              << " hit points!" << RESET << std::endl;
}

void ClapTrap::setHitPoint(unsigned int value) {
    this->hitPoint = value;
}
void ClapTrap::setEnergyPoint(unsigned int value) {
    this->energyPoints = value;
}
void ClapTrap::setAttackDamage(unsigned int value) {
    this->attackDamage = value;
}

std::string ClapTrap::getName() const {
    return name;
}
unsigned int ClapTrap::getHitPoint(void) const {
    return hitPoint;
}
unsigned int ClapTrap::getEnergyPoint(void) const {
    return energyPoints;
}
unsigned int ClapTrap::getAttackDamage(void) const {
    return attackDamage;
}

ClapTrap::~ClapTrap() {
    std::cout << BRED << "ClapTrap destructor called " << name << RESET << std::endl;
}