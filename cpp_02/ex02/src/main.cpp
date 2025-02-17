/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:25:10 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/12 16:32:47 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "color.h" 

int main() {

	Fixed a(1.123456f);
	Fixed b(2.654321f);
	Fixed c = a * b;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a * b = " << c << std::endl;
    // std::cout << BYELLOW << "Testing Fixed class" << RESET << std::endl << std::endl;
    
    // std::cout << BBLUE << "Constructors" << RESET << std::endl;
    // Fixed a;
    // Fixed b(10);
    // Fixed c(42.42f);
    // Fixed d(b);

    // std::cout << std::endl << BBLUE << "Assignment operator" << RESET << std::endl;
    // a = c;

    // std::cout << std::endl << BBLUE << "Getters/Setters" << RESET << std::endl;
    // std::cout << "a: " << a << " (raw: " << a.getRawBits() << ")" << std::endl;
    // a.setRawBits(256);
    // std::cout << "a after setRawBits(256): " << a << " (raw: " << a.getRawBits() << ")" << std::endl;

    // std::cout << std::endl << BBLUE << "Arithmetic operators" << RESET << std::endl;
    // Fixed e = b + c;
    // std::cout << b << " + " << c << " = " << e << std::endl;
    // Fixed f = c - b;
    // std::cout << c << " - " << b << " = " << f << std::endl;
    // Fixed g = b * c;
    // std::cout << b << " * " << c << " = " << g << std::endl;
    // Fixed h = c / b;
    // std::cout << c << " / " << b << " = " << h << std::endl;

    // std::cout << std::endl << BBLUE << "Comparison operators" << RESET << std::endl;
    // std::cout << b << " > " << c << " ? " << (b > c ? "true" : "false") << std::endl;
    // std::cout << b << " < " << c << " ? " << (b < c ? "true" : "false") << std::endl;
    // std::cout << b << " >= " << c << " ? " << (b >= c ? "true" : "false") << std::endl;
    // std::cout << b << " <= " << c << " ? " << (b <= c ? "true" : "false") << std::endl;
    // std::cout << b << " == " << c << " ? " << (b == c ? "true" : "false") << std::endl;
    // std::cout << b << " != " << c << " ? " << (b != c ? "true" : "false") << std::endl;

    // std::cout << std::endl << BBLUE << "Increment/Decrement operators" << RESET << std::endl;
    // Fixed x;
    // std::cout << "x: " << x << std::endl;
    // std::cout << "x++: " << x++ << std::endl;
    // std::cout << "x: " << x << std::endl;
    // std::cout << "++x: " << ++x << std::endl;
    // std::cout << "x--: " << x-- << std::endl;
    // std::cout << "x: " << x << std::endl;
    // std::cout << "--x: " << --x << std::endl;

    // std::cout << std::endl << BBLUE << "Min/Max functions" << RESET << std::endl;
    // std::cout << "min(" << b << ", " << c << ") = " << Fixed::min(b, c) << std::endl;
    // std::cout << "max(" << b << ", " << c << ") = " << Fixed::max(b, c) << std::endl;

    return 0;
}
