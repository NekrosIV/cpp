/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/23 15:34:21 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "MutantStack.hpp"
#include <vector>
#include <list>

int main() {
    std::cout << BCYAN << "\n=== TESTING MUTANTSTACK ===\n" << RESET << std::endl;

    MutantStack<int> mstack;

    std::cout << BYELLOW << "[TEST 1] Pushing elements into MutantStack" << RESET << std::endl;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(42);
    mstack.push(22);

    std::cout << "Stack top element: " << BWHITE << mstack.top() << RESET << std::endl;
    mstack.pop();
    std::cout << "New top after pop: " << BWHITE << mstack.top() << RESET << std::endl;
    std::cout << "Stack size: " << BWHITE << mstack.size() << RESET << std::endl;

    std::cout << BYELLOW << "\n[TEST 2] Iterating through MutantStack" << RESET << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "MutantStack elements: ";
    while (it != ite) {
        std::cout << BGREEN << *it << " " << RESET;
        ++it;
    }
    std::cout << std::endl;

    std::cout << "\n-----------------------------\n" << std::endl;

    std::cout << BCYAN << "=== COMPARING WITH OTHER CONTAINERS ===\n" << RESET << std::endl;

    std::cout << BYELLOW << "[TEST 3] Using std::vector instead of MutantStack" << RESET << std::endl;
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(17);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    vec.push_back(42);
    vec.push_back(22);

    std::cout << "Vector elements: ";
    for (std::vector<int>::iterator vit = vec.begin(); vit != vec.end(); ++vit) {
        std::cout << BBLUE << *vit << " " << RESET;
    }
    std::cout << std::endl;

    std::cout << BYELLOW << "\n[TEST 4] Using std::list instead of MutantStack" << RESET << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(42);
    lst.push_back(22);

    std::cout << "List elements: ";
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit) {
        std::cout << BMAGENTA << *lit << " " << RESET;
    }
    std::cout << std::endl;

    std::cout << BYELLOW << "\n[TEST 5] Using std::stack (No Iterators Available)" << RESET << std::endl;
    std::stack<int> s;
    s.push(5);
    s.push(17);
    s.push(3);
    s.push(5);
    s.push(737);
    s.push(42);
    s.push(22);

    std::cout << "Stack elements (LIFO order): ";
    while (!s.empty()) {
        std::cout << BRED << s.top() << " " << RESET;
        s.pop();
    }
    std::cout << std::endl;

    std::cout << BCYAN << "\n=== END OF TESTS ===\n" << RESET << std::endl;

    return 0;
}
