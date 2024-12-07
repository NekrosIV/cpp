/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:25:10 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/07 15:31:41 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cstdlib>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 9)
		return (0);
	Point A(std::atof(av[1]), std::atof(av[2]));
	Point B(std::atof(av[3]), std::atof(av[4]));
	Point C(std::atof(av[5]), std::atof(av[6]));
	Point P(std::atof(av[7]), std::atof(av[8]));

	if (bsp(A, B, C, P))
	{
		std::cout << "Point is inside the triangle." << std::endl;
	}
	else
	{
		std::cout << "Point is outside the triangle" << std::endl;
	}

	return (0);
}