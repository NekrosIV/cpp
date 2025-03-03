/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:02:11 by kasingh           #+#    #+#             */
/*   Updated: 2025/03/03 16:33:20 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

class PmergeMe
{
  private:
	std::vector<std::pair<int, int> > createSortedPairs(std::vector<int> &arr);
	std::deque<std::pair<int, int> > createSortedPairsDeque(std::deque<int> &arr);
	int findInsertPosition(std::vector<int> &sortedList, int value, int upperBound);
	int findInsertPositionDeque(std::deque<int> &sortedList, int value, int upperBound);
	int sequenceJacobsthal(int n);

  public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	std::vector<int> fordJohnsonSortVector(std::vector<int> &arr);
	std::deque<int> fordJohnsonSortDeque(std::deque<int> &arr);
};
