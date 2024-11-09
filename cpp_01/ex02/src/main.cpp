/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:46:58 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/06 15:13:58 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string myString = "HI THIS IS BRAIN";
	std::string *stringPTR = &myString;
	std::string &stringREF = myString;
    
	std::cout << "The address of myString  : " << &myString << std::endl;
	std::cout << "The address in stringPTR : " << stringPTR << std::endl;
	std::cout << "The address in stringREF : " << &stringREF << std::endl;
    
	std::cout << "The value of myString  : " << myString << std::endl;
	std::cout << "The value of stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value of stringREF : " << stringREF << std::endl;
}
