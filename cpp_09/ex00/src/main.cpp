/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/26 16:08:52 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    try {
        if (ac != 2) {
            std::cerr << "Usage: ./btc <input_file>\n";
            return 1;
        }

        BitcoinExchange btc(av[1]);
         btc.processInputFile();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

