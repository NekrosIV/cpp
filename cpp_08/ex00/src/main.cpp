/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/19 16:34:05 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "easyfind.hpp"

void testVector() {
    std::cout << BBLUE << "🟢 Testing with std::vector<int>...\n" << RESET;
    
    std::vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i * 10); // {10, 20, 30, 40, 50}

    try {
        std::cout << BGREEN << "Searching for 30... " << RESET;
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << BMAGENTA << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << BRED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BYELLOW << "Searching for 100... " << RESET;
        std::vector<int>::iterator it = easyfind(vec, 100); // 🚨 Erreur attendue
        std::cout << BMAGENTA << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << BRED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testList() {
    std::cout << BBLUE << "🟢 Testing with std::list<int>...\n" << RESET;
    
    std::list<int> lst;
    for (int i = 5; i <= 25; i += 5)
        lst.push_back(i); // {5, 10, 15, 20, 25}

    try {
        std::cout << BGREEN << "Searching for 15... " << RESET;
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << BMAGENTA << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << BRED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BYELLOW << "Searching for 50... " << RESET;
        std::list<int>::iterator it = easyfind(lst, 50); // 🚨 Erreur attendue
        std::cout << BMAGENTA << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << BRED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testEmptyContainer() {
    std::cout << BBLUE << "🟢 Testing with an empty std::vector<int>...\n" << RESET;
    
    std::vector<int> emptyVec;

    try {
        std::cout << BYELLOW << "Searching for 10 in empty vector... " << RESET;
        std::vector<int>::iterator it = easyfind(emptyVec, 10); // 🚨 Erreur attendue
        std::cout << BMAGENTA << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << BRED << "Error: " << e.what() << RESET << std::endl;
    }
}

int main() {
    std::cout << BCYAN << "🔹 Running tests on different containers...\n\n" << RESET;
    
    testVector();
    std::cout << std::endl;

    testList();
    std::cout << std::endl;

    testEmptyContainer();
    
    std::cout << BCYAN << "\n✅ All tests completed!\n" << RESET;
    return 0;
}
