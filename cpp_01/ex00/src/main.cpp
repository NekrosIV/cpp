/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:25:10 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/06 13:31:00 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie Zombie1("Polo");
	Zombie1.announce();
	Zombie* zombie1 = newZombie("yolo");
	zombie1->announce();
	delete zombie1;
	randomChump("Bob");
	return (0);
}
