/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:16:28 by kasingh           #+#    #+#             */
/*   Updated: 2024/10/22 18:06:01 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				std::cout << static_cast<char>(toupper(av[i][j]));
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
}
