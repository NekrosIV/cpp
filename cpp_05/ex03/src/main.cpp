/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:22:07 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/12 14:03:38 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "color.h"
#include <iostream>

int main()
{
    std::cout << BMAGENTA << "\n===== TESTING INTERN FORM CREATION =====" << RESET << std::endl;

    Intern intern;
    AForm *form1;
    AForm *form2;
    AForm *form3;
    AForm *form4;

    form1 = intern.makeForm("shrubbery creation", "Aramaki");   
    form2 = intern.makeForm("robotomy request", "Bender");     
    form3 = intern.makeForm("presidential pardon", "Human");   
    form4 = intern.makeForm("invalid form", "Unknown");

    std::cout << BBLUE << "\n===== TESTING FORM SIGNATURE & EXECUTION =====" << RESET << std::endl;

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 140);

    if (form1)
    {
        std::cout << BCYAN << "🎭 Before signing: " << *form1 << RESET << std::endl;
        worker.signForm(*form1); 
        boss.signForm(*form1);   
        std::cout << BGREEN << "✅ After signing: " << *form1 << RESET << std::endl;
        worker.executeForm(*form1); 
        boss.executeForm(*form1);
        delete form1;
    }


    if (form2)
    {
        std::cout << BCYAN << "🎭 Before signing: " << *form2 << RESET << std::endl;
        boss.signForm(*form2);   
        std::cout << BGREEN << "✅ After signing: " << *form2 << RESET << std::endl;
        worker.executeForm(*form2); 
        boss.executeForm(*form2);
        delete form2;
    }

    if (form3)
    {
        std::cout << BCYAN << "🎭 Before signing: " << *form3 << RESET << std::endl;
        worker.signForm(*form3); 
        boss.signForm(*form3);   
        std::cout << BGREEN << "✅ After signing: " << *form3 << RESET << std::endl;
        worker.executeForm(*form3); 
        boss.executeForm(*form3);   
        delete form3;
    }

    if (form4)
    {
        delete form4; // Ne devrait jamais être alloué
    }

    std::cout << BMAGENTA << "\n===== END OF TESTS =====" << RESET << std::endl;
    return 0;
}


