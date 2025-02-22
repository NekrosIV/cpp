/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/22 16:46:30 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "color.hpp"

int main() {
    srand(time(NULL));
    std::cout << BCYAN << "\n=== TESTING SPAN CLASS ===\n" << RESET << std::endl;

    try {
        std::cout << BYELLOW << "[TEST 1] Creating a Span of size 5 and adding 5 numbers" << RESET << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << BGREEN << "✔ Successfully added numbers!" << RESET << std::endl;
        std::cout << "Shortest Span: " << BWHITE << sp.shortestSpan() << RESET << std::endl;
        std::cout << "Longest Span: " << BWHITE << sp.longestSpan() << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n-----------------------------\n" << std::endl;

    try {
        std::cout << BYELLOW << "[TEST 2] Adding too many numbers (should throw an exception)" << RESET << std::endl;
        Span sp(3);
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
        sp.addNumber(40); // Should throw an exception

        std::cout << BRED << "❌ This message should not be displayed!" << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << BGREEN << "✔ Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n-----------------------------\n" << std::endl;

    try {
        std::cout << BYELLOW << "[TEST 3] Not enough numbers for shortestSpan() (should throw an exception)" << RESET << std::endl;
        Span sp(5);
        sp.addNumber(42);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;  // Should throw an exception
    } catch (const std::exception &e) {
        std::cerr << BGREEN << "✔ Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n-----------------------------\n" << std::endl;

    try {
        std::cout << BYELLOW << "[TEST 4] Adding 10,000 random numbers" << RESET << std::endl;
        Span bigSpan(10000);
        for (int i = 0; i < 10000; i++)
            bigSpan.addNumber(rand() % 100000); // Random numbers

        std::cout << "Shortest Span: " << BWHITE << bigSpan.shortestSpan() << RESET << std::endl;
        std::cout << "Longest Span: " << BWHITE << bigSpan.longestSpan() << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n-----------------------------\n" << std::endl;

    try {
        std::cout << BYELLOW << "[TEST 5] Adding numbers using a range of iterators (addRange)" << RESET << std::endl;
        std::vector<int> values;
        values.push_back(10);
        values.push_back(20);
        values.push_back(30);
        values.push_back(40);
        values.push_back(50);

        Span sp(10);
        sp.addRange(values.begin(), values.end());

        std::cout << BGREEN << "✔ Successfully added numbers using range!" << RESET << std::endl;
        std::cout << "Shortest Span: " << BWHITE << sp.shortestSpan() << RESET << std::endl;
        std::cout << "Longest Span: " << BWHITE << sp.longestSpan() << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << BRED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n-----------------------------\n" << std::endl;

    try {
        std::cout << BYELLOW << "[TEST 6] Adding too many numbers via range (should throw an exception)" << RESET << std::endl;
        std::vector<int> largeVec(15, 100); // Vector of 15 elements, all set to 100
        Span sp(10);
        sp.addRange(largeVec.begin(), largeVec.end()); // Should throw an exception

        std::cout << BRED << "❌ This message should not be displayed!" << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << BGREEN << "✔ Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BCYAN << "\n=== END OF TESTS ===\n" << RESET << std::endl;
    return 0;
}
