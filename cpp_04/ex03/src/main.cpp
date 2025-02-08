/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:50:49 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/07 14:41:50 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#include "color.h"


int main()
{
    std::cout << BYELLOW << "==== START OF TESTS ====" << RESET << std::endl;

    std::cout << BGREEN << "[TEST] Creating MateriaSource" << RESET << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << BGREEN << "[TEST] Creating Characters" << RESET << std::endl;
    ICharacter* me = new Character("Alice");
    ICharacter* bob = new Character("Bob");

    std::cout << BCYAN << "[TEST] Equipping Materias" << RESET << std::endl;
    AMateria* tmp;
    AMateria* tmp2;


    tmp = src->createMateria("ice");
    if (tmp) 
    { 
        me->equip(tmp);
        me->equip(tmp);
    }
    
    tmp2 = src->createMateria("cure");
    if (tmp2) 
        me->equip(tmp2);

    std::cout << BBLUE << "[INFO] Alice uses her materias on Bob" << RESET << std::endl;
    me->use(0, *bob);  // "* shoots an ice bolt at Bob *"
    me->use(1, *bob);  // "* heals Bob's wounds *"

    std::cout << BMAGENTA << "[TEST] Unequipping Materias" << RESET << std::endl;
    me->unequip(0);
    delete(tmp);
    me->use(0, *bob); 

    std::cout << BYELLOW << "[TEST] Trying to overfill inventory" << RESET << std::endl;
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    tmp = src->createMateria("ice");
    if (tmp) 
        me->equip(tmp);

    std::cout << BRED << "[TEST] Deleting Characters and MateriaSource" << RESET << std::endl;
    delete bob;
    delete me;
    delete src;
    delete tmp;

    std::cout << BYELLOW << "==== END OF TESTS ====" << RESET << std::endl;
    return 0;
}

