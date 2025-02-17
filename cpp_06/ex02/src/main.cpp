/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/17 11:25:08 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "color.h"

Base	*generate(void)
{
	int	random;

	std::srand(std::time(0));
	random = std::rand() % 3;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << BGREEN << "Type identified: A" << RESET << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << BYELLOW << "Type identified: B" << RESET << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << BCYAN << "Type identified: C" << RESET << std::endl;
    else
        std::cout << BRED << "Unknown type" << RESET << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void) dynamic_cast<A &>(p);
        std::cout << BGREEN << "Type identified: A" << RESET << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void) dynamic_cast<B &>(p);
        std::cout << BYELLOW << "Type identified: B" << RESET << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void) dynamic_cast<C &>(p);
        std::cout << BCYAN << "Type identified: C" << RESET << std::endl;
        return;
    }
    catch (...) {}

    std::cout << BRED << "Unknown type" << RESET << std::endl;
}

int main() {
    std::cout << BBLUE << "🔍 Generating a random object..." << RESET << std::endl;
    Base* obj = generate();

    std::cout << BMAGENTA << "Identifying with pointer: " << RESET;
    identify(obj);

    std::cout << BMAGENTA << "Identifying with reference: " << RESET;
    identify(*obj);

    delete obj;
    std::cout << BBLUE << "✅ Object deleted. Exiting program." << RESET << std::endl;
    return 0;
}
