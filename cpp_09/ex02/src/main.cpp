/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:46 by kasingh           #+#    #+#             */
/*   Updated: 2025/03/03 17:33:34 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip> 
#include <set> 
#include <cstdlib> 
#include <string>
#include "color.hpp"
#include <climits>

std::vector<int> parsing(int ac, char **av) 
{
    std::vector<int> sequence;
    std::set<int> uniqueNumbers;

    for (int i = 1; i < ac; i++) 
    {
        char *endPtr;
        long num = std::strtol(av[i], &endPtr, 10);  

        if (*endPtr != '\0') 
            throw std::runtime_error("Error: Invalid number format → '" + std::string(av[i]) + "'");
        

        if (num <= 0 || num > INT_MAX) 
            throw std::out_of_range("Error: Number out of valid range → '" + std::string(av[i]) + "'");
        

        int validNum = static_cast<int>(num);

        if (!uniqueNumbers.insert(validNum).second) 
            throw std::runtime_error("Error: Duplicate number detected → '" + std::string(av[i]) + "'");
        

        sequence.push_back(validNum);
    }

    return sequence;
}

int main(int ac, char **av) {
    if (ac < 2) 
    {
        std::cerr << "Usage: ./PmergeMe <list of positive integers>" << std::endl;
        return 1;
    }

    try 
    {
        PmergeMe sorter;

        clock_t start = clock();
        std::vector<int> sequenceVec = parsing(ac, av);
        std::vector<int> sortedVec = sorter.fordJohnsonSortVector(sequenceVec);
        clock_t end = clock();
        double elapsedVectorTime = double(end - start);

        std::cout << "Before sorting (vector): ";
        for (size_t i = 0; i < sequenceVec.size(); i++)
            std::cout << sequenceVec[i] << " ";
        std::cout << std::endl;

        std::cout << "After sorting (vector): ";
        for (size_t i = 0; i < sortedVec.size(); i++)
            std::cout << sortedVec[i] << " ";
        std::cout << std::endl;

        std::cout << std::fixed << "Time taken using std::vector: " 
                  << std::setprecision(6) << elapsedVectorTime << " us" << std::endl;

        start = clock();
        std::vector<int> sequenceDeq = parsing(ac, av);
        std::deque<int> deqToSort(sequenceDeq.begin(), sequenceDeq.end());
        std::deque<int> sortedDeq = sorter.fordJohnsonSortDeque(deqToSort);
        end = clock();
        double elapsedDequeTime = double(end - start);

        std::cout << std::fixed << "Time taken using std::deque: " 
                  << std::setprecision(6) << elapsedDequeTime << " us" << std::endl;

    } 
    catch (const std::exception &e) 
    {
        std::cerr << BRED << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}