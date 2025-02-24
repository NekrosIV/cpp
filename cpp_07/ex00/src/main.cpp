/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/17 17:25:33 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.hpp"
#include "color.hpp"
#include <iostream>

int main() {
    int x = 42, y = 24;
    
    std::cout << BBLUE << "Befor swap: x = " << x << ", y = " << y << RESET << std::endl;
    swap(x, y);
    std::cout << BGREEN << "After swap: x = " << x << ", y = " << y << RESET << std::endl;
    
    std::cout << BYELLOW << "min(x, y) = " << ::min(x, y) << RESET << std::endl;
    std::cout << BRED << "max(x, y) = " << ::max(x, y) << RESET << std::endl;

    std::string a = "hello", b = "world";
    
    std::cout << BMAGENTA << "Befor swap: a = " << a << ", b = " << b << RESET << std::endl;
    swap(a, b);
    std::cout << BCYAN << "After swap: a = " << a << ", b = " << b << RESET << std::endl;

    std::cout << BYELLOW << "min(a, b) = " << ::min(a, b) << RESET << std::endl;
    std::cout << BRED << "max(a, b) = " << ::max(a, b) << RESET << std::endl;

    return 0;
}
