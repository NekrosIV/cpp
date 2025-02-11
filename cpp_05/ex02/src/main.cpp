/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:22:07 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/11 17:37:40 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "color.h"


int main()
{
    std::cout << BMAGENTA << "\n===== TESTING SHRUBBERY CREATION FORM =====" << RESET << std::endl;

    ShrubberyCreationForm tree("Garden");
    Bureaucrat bob("Bob", 140);
    Bureaucrat alice("Alice", 1);

    std::cout << BCYAN << "🎭 Before signing: " << tree << RESET << std::endl;
    bob.signForm(tree);  
    alice.signForm(tree);  
    std::cout << BGREEN << "✅ After signing: " << tree << RESET << std::endl;

    bob.executeForm(tree); 
    alice.executeForm(tree); 


    std::cout << BBLUE << "\n===== TESTING ROBOTOMY REQUEST FORM =====" << RESET << std::endl;

    RobotomyRequestForm robot("Bender");
    Bureaucrat charlie("Charlie", 50);
    Bureaucrat dave("Dave", 10);

    std::cout << BCYAN << "🎭 Before signing: " << robot << RESET << std::endl;
    charlie.signForm(robot); 
    dave.signForm(robot);  
    std::cout << BGREEN << "✅ After signing: " << robot << RESET << std::endl;

    charlie.executeForm(robot); 
    dave.executeForm(robot);  


    std::cout << BYELLOW << "\n===== TESTING PRESIDENTIAL PARDON FORM =====" << RESET << std::endl;

    PresidentialPardonForm pardon("Human");
    Bureaucrat yupi("Yupi", 30);
    Bureaucrat neferupito("Neferupito", 1);

    std::cout << BCYAN << "🎭 Before signing: " << pardon << RESET << std::endl;
    yupi.signForm(pardon); 
    neferupito.signForm(pardon);  
    std::cout << BGREEN << "✅ After signing: " << pardon << RESET << std::endl;

    yupi.executeForm(pardon); 
    neferupito.executeForm(pardon);  

    std::cout << BMAGENTA << "\n===== END OF TESTS =====" << RESET << std::endl;
    return 0;
}

