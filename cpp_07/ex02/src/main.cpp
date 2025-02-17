/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:06:37 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/17 18:12:02 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib> // Pour srand() et rand()
#include <ctime>   // Pour time()


#define MAX_VAL 750

int	main(int, char **)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //
	return (0);
}


// int main() {
//     try {
//         // 🟢 Création d'un tableau d'entiers
//         Array<int> numbers(5);
//         for (unsigned int i = 0; i < numbers.size(); i++)
//             numbers[i] = i * 10;

//         // Affichage du tableau
//         std::cout << "Integer array: ";
//         for (unsigned int i = 0; i < numbers.size(); i++)
//             std::cout << numbers[i] << " ";
//         std::cout << std::endl;

//         // 🟢 Test de l'opérateur de copie
//         Array<int> copyNumbers = numbers;
//         std::cout << "Copied array: ";
//         for (unsigned int i = 0; i < copyNumbers.size(); i++)
//             std::cout << copyNumbers[i] << " ";
//         std::cout << std::endl;

//         // 🟢 Test de l'exception (accès hors limites)
//         std::cout << "Accessing out of bounds: " << numbers[10] << std::endl;

//     } catch (const std::exception& e) {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }