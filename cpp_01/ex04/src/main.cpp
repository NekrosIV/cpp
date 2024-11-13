/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:17:16 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/13 15:03:56 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	size_t	pos;

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
		std::perror(filename.c_str());
		return (1);
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::perror((filename + ".replace").c_str());
		return (1);
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::string modifiedLine;
		pos = 0;
		while ((pos = line.find(src, pos)) != std::string::npos)
		{
			modifiedLine += line.substr(0, pos) + dest;
			line = line.substr(pos + src.length());
			pos = 0;
		}
		modifiedLine += line;
		outputFile << modifiedLine << std::endl;
	}
	return (0);
}
