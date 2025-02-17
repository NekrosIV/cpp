/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/17 10:46:25 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include "color.h"
#include <iostream>

int	main(void)
{
	std::cout << BBLUE << "Starting Serializer Test..." << RESET << std::endl;

	Data myData;
	myData.info = "Hello, Serializer!";

	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << BYELLOW << "Pointer converted to uintptr_t: " << RESET << raw << std::endl;

	Data *ptr = Serializer::deserialize(raw);

	if (ptr == &myData)
	{
		std::cout << BGREEN << "Success: Pointers match!" << RESET << std::endl;
		std::cout << BCYAN << "Retrieved info: " << RESET << ptr->info << std::endl;
	}
	else
	{
		std::cout << BRED << "Error: Deserialization failed!" << RESET << std::endl;
	}

	std::cout << BBLUE << "Serializer Test Completed." << RESET << std::endl;
	return (0);
}