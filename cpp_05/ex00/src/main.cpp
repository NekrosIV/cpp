/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/11 13:25:47 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "color.h"

int main()
{
    std::cout << BMAGENTA << "===== TESTING BUREAUCRAT CREATION =====" << RESET << std::endl;

    try {
        Bureaucrat b1("Alice", 1);
        std::cout << BGREEN << "✅ Successfully created: " << b1 << RESET << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 150);
        std::cout << BGREEN << "✅ Successfully created: " << b2 << RESET << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 0);
        std::cout << BRED << "❌ This should not be printed: " << b3 << RESET << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception caught (too high): " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat b4("David", 151);
        std::cout << BRED << "❌ This should not be printed: " << b4 << RESET << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception caught (too low): " << e.what() << RESET << std::endl;
    }

    std::cout << BBLUE << "\n===== TESTING GRADE INCREMENTATION & DECREMENTATION =====" << RESET << std::endl;

    try {
        Bureaucrat b5("Eve", 2);
        std::cout << BCYAN << "🎭 Before increment: " << b5 << RESET << std::endl;
        b5.incrementGrade();
        std::cout << BGREEN << "✅ After increment: " << b5 << RESET << std::endl;

        std::cout << BCYAN << "🎭 Trying to increment grade at max level..." << RESET << std::endl;
        b5.incrementGrade(); 
    }
    catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat b6("Frank", 149);
        std::cout << BCYAN << "🎭 Before decrement: " << b6 << RESET << std::endl;
        b6.decrementGrade();
        std::cout << BGREEN << "✅ After decrement: " << b6 << RESET << std::endl;

        std::cout << BCYAN << "🎭 Trying to decrement grade at min level..." << RESET << std::endl;
        b6.decrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BYELLOW << "\n===== TESTING COPY CONSTRUCTOR & ASSIGNMENT OPERATOR =====" << RESET << std::endl;

    Bureaucrat b7("George", 100);
    std::cout << BCYAN << "🎭 Original: " << b7 << RESET << std::endl;

    Bureaucrat b8 = b7; 
    std::cout << BGREEN << "✅ Copied: " << b8 << RESET << std::endl;

    Bureaucrat b9("Henry", 50);
    std::cout << BCYAN << "🎭 Before assignment: " << b9 << RESET << std::endl;
    b9 = b7;
    std::cout << BGREEN << "✅ After assignment: " << b9 << RESET << std::endl;

    std::cout << BMAGENTA << "\n===== END OF TESTS =====" << RESET << std::endl;
    return 0;
}
