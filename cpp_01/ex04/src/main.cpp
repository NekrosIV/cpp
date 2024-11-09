/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:17:16 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/09 16:27:47 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	std::string filename;
	std::string src;
	std::string dest;
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <src> <dest>" << std::endl;
		return (1);
	}
	filename = av[1];
	src = av[2];
	dest = av[3];
	if (src.empty() || dest.empty())
	{
		std::cerr << "Error: src and dest cannot be empty strings." << std::endl;
		return (1);
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Erreur : impossible d'ouvrir le fichier '" << filename << "'." << std::endl;
		std::cerr << "Raison : " << std::strerror(errno) << std::endl;
		return (1);
	}
	return (0);
}
