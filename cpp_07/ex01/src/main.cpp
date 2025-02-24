/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/17 17:36:44 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "template.hpp"
#include <iostream>

void	printInt(int x)
{
	std::cout << x << " ";
}

void	printString(const std::string &str)
{
	std::cout << str << " ";
}

int	main(void)
{
	int tab[] = {1, 2, 3, 4, 5};
	std::cout << "Integer array: ";
	iter(tab, 5, printInt);
	std::cout << std::endl;

	std::string words[] = {"Hello", "World", "42"};
	std::cout << "String array: ";
	iter(words, 3, printString);
	std::cout << std::endl;

	return (0);
}