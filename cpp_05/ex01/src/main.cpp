/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/11 14:32:11 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.h"

int main()
{
    std::cout << BMAGENTA << "\n===== TESTING FORM CREATION =====" << RESET << std::endl;

    try {
        Form validForm("Top Secret Document", 10, 5);
        std::cout << BGREEN << "✅ Successfully created: " << validForm << RESET << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        Form invalidFormHigh("Impossible Form", 0, 5);
    }
    catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception caught (too high grade): " << e.what() << RESET << std::endl;
    }

    try {
        Form invalidFormLow("Trash Form", 151, 100);
    }
    catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception caught (too low grade): " << e.what() << RESET << std::endl;
    }

    std::cout << BBLUE << "\n===== TESTING FORM SIGNING =====" << RESET << std::endl;

    Bureaucrat alice("Alice", 5);
    Bureaucrat bob("Bob", 50);
    Bureaucrat charlie("Charlie", 15);
    Form f1("Confidential Report", 20, 10);

    std::cout << BCYAN << "🎭 Before signing: " << f1 << RESET << std::endl;
    bob.signForm(f1);
    charlie.signForm(f1); 
    std::cout << BGREEN << "✅ After signing: " << f1 << RESET << std::endl;

    std::cout << BYELLOW << "\n===== TESTING MULTIPLE SIGN ATTEMPTS =====" << RESET << std::endl;
    std::cout << BCYAN << "🎭 Attempting to sign an already signed form..." << RESET << std::endl;
    alice.signForm(f1);

    std::cout << BBLUE << "\n===== TESTING MULTIPLE FORMS =====" << RESET << std::endl;

    Form f2("Project Budget", 50, 30);
    Form f3("Security Clearance", 5, 2);

    std::cout << BCYAN << "🎭 Forms before signing:" << RESET << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    bob.signForm(f2); 
    alice.signForm(f3); 

    std::cout << BGREEN << "✅ Forms after signing:" << RESET << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    std::cout << BRED << "\n===== TESTING EXCEPTION HANDLING =====" << RESET << std::endl;

    try {
        Form f4("Impossible to Sign", 1, 1);
        Bureaucrat dave("Dave", 50);
        dave.signForm(f4); 
    }
    catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BMAGENTA << "\n===== END OF TESTS =====" << RESET << std::endl;
    return 0;
}


