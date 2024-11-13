/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:19:57 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/13 17:52:09 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "color.h"

void print_available_cmd() {
    std::cout << BRED << "╔══════════════════════════════╗" << RESET << std::endl;
    std::cout << BRED << "║       " << BYELLOW << "Available Levels" << BRED << "       ║" << RESET << std::endl;
    std::cout << BRED << "╠══════════════════════════════╣" << RESET << std::endl;
    std::cout << BRED << "║ " << BGREEN << "DEBUG" << BRED << "   - Debug level        ║" << RESET << std::endl;
    std::cout << BRED << "║ " << BBLUE << "INFO" << BRED << "    - Information level  ║" << RESET << std::endl;
    std::cout << BRED << "║ " << BYELLOW << "WARNING" << BRED << " - Warning level      ║" << RESET << std::endl;
    std::cout << BRED << "║ " << BRED << "ERROR" << BRED << "   - Error level        ║" << RESET << std::endl;
    std::cout << BRED << "╚══════════════════════════════╝" << RESET << std::endl;
}

int main(int ac, char **av) {
    Harl harl;
    if (ac != 2) 
    {
        std::cerr << "Usage: " << av[0] << " <level>" << std::endl;
        print_available_cmd();
        return 1;
    }

    harl.complain(av[1]);
    return 0;
}