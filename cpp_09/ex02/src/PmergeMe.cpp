/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:16:30 by kasingh           #+#    #+#             */
/*   Updated: 2025/03/03 17:29:52 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
	return (*this);
}
PmergeMe::~PmergeMe()
{
}

std::deque<std::pair<int, int> > PmergeMe::createSortedPairsDeque(std::deque<int> &arr) {
    std::deque<std::pair<int, int> > sortedPairs;

    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        int smaller = std::min(arr[i], arr[i + 1]);
        int larger = std::max(arr[i], arr[i + 1]);
        sortedPairs.push_back(std::make_pair(smaller, larger));
    }

    return sortedPairs;
}

int PmergeMe::findInsertPositionDeque(std::deque<int> &sortedList, int value, int upperBound) {
    int lowerBound = 0, middle;

    while (lowerBound <= upperBound) {
        middle = (lowerBound + upperBound) / 2;
        if (sortedList[middle] > value)
            upperBound = middle - 1;
        else
            lowerBound = middle + 1;
    }

    return (sortedList[middle] < value) ? middle + 1 : middle;
}

std::vector<std::pair<int, int> > PmergeMe::createSortedPairs(std::vector<int> &arr) 
{
    std::vector<std::pair<int, int> > sortedPairs;

    for (size_t i = 0; i + 1 < arr.size(); i += 2) 
    {
        int smaller = std::min(arr[i], arr[i + 1]);
        int larger = std::max(arr[i], arr[i + 1]);
        sortedPairs.push_back(std::make_pair(smaller, larger));
    }

    return sortedPairs;
}

int PmergeMe::findInsertPosition(std::vector<int> &sortedList, int value, int upperBound) 
{
    int lowerBound = 0, middle;

    while (lowerBound <= upperBound) 
    {
        middle = (lowerBound + upperBound) / 2;
        if (sortedList[middle] > value)
            upperBound = middle - 1;
        else
            lowerBound = middle + 1;
    }

    return (sortedList[middle] < value) ? middle + 1 : middle;
}

int PmergeMe::sequenceJacobsthal(int n) 
{
    int jPrev = 0, jCurr = 1;

    if (n == 0) return jPrev;
    if (n == 1) return jCurr;

    int jNext;
    for (int i = 2; i <= n; i++) 
    {
        jNext = jCurr + 2 * jPrev;
        jPrev = jCurr;
        jCurr = jNext;
    }

    return jNext;
}




std::vector<int> PmergeMe::fordJohnsonSortVector(std::vector<int> &arr) 
{
    if (arr.size() <= 1) 
        return arr;

    std::vector<std::pair<int, int> > sortedPairs = createSortedPairs(arr);

    std::vector<int> mainList;
    std::vector<int> pendingElements;
    for (size_t i = 0; i < sortedPairs.size(); i++) 
        mainList.push_back(sortedPairs[i].second);

    mainList = fordJohnsonSortVector(mainList);

    for (size_t i = 0; i < mainList.size(); i++) 
    {
        for (size_t j = 0; j < sortedPairs.size(); j++) 
        {
            if (sortedPairs[j].second == mainList[i]) 
            {
                pendingElements.push_back(sortedPairs[j].first);
                break;
            }
        }
    }

    mainList.insert(mainList.begin(), pendingElements.front());

    int insertionLimit = 1;
    int jacobIndex = 3;
    int powerOf2 = 4; 

    while (true) 
    {
        int jacobValue = sequenceJacobsthal(jacobIndex);
        if (jacobValue >= static_cast<int>(pendingElements.size()))
            break;

        for (int i = jacobValue; i >= insertionLimit; --i) 
        {
            int insertPos = findInsertPosition(mainList, pendingElements[i], powerOf2 - 1);
            mainList.insert(mainList.begin() + insertPos, pendingElements[i]);
        }

        insertionLimit = jacobValue + 1;
        ++jacobIndex;
        powerOf2 *= 2;
    }

    for (size_t i = insertionLimit; i < pendingElements.size(); ++i) 
    {
        int insertPos = findInsertPosition(mainList, pendingElements[i], mainList.size() - 1);
        mainList.insert(mainList.begin() + insertPos, pendingElements[i]);
    }

    if (arr.size() % 2) 
    {
        int lastValue = arr.back();
        int insertPos = findInsertPosition(mainList, lastValue, mainList.size() - 1);
        mainList.insert(mainList.begin() + insertPos, lastValue);
    }

    return mainList;
}



std::deque<int> PmergeMe::fordJohnsonSortDeque(std::deque<int> &arr) 
{
    if (arr.size() <= 1) return arr;

    std::deque<std::pair<int, int> > sortedPairs = createSortedPairsDeque(arr);

    std::deque<int> mainList;
    std::deque<int> pendingElements;
    for (size_t i = 0; i < sortedPairs.size(); i++) 
        mainList.push_back(sortedPairs[i].second);

    mainList = fordJohnsonSortDeque(mainList);

    for (size_t i = 0; i < mainList.size(); i++) 
    {
        for (size_t j = 0; j < sortedPairs.size(); j++) 
        {
            if (sortedPairs[j].second == mainList[i]) 
            {
                pendingElements.push_back(sortedPairs[j].first);
                break;
            }
        }
    }

    mainList.push_front(pendingElements.front());

    int insertionLimit = 1;
    int jacobIndex = 3;
    int powerOf2 = 4; 

    while (true) 
    {
        int jacobValue = sequenceJacobsthal(jacobIndex);
        if (jacobValue >= static_cast<int>(pendingElements.size()))
            break;

        for (int i = jacobValue; i >= insertionLimit; --i) 
        {
            int insertPos = findInsertPositionDeque(mainList, pendingElements[i], powerOf2 - 1);
            mainList.insert(mainList.begin() + insertPos, pendingElements[i]);
        }

        insertionLimit = jacobValue + 1;
        ++jacobIndex;
        powerOf2 *= 2;
    }

    for (size_t i = insertionLimit; i < pendingElements.size(); ++i) 
    {
        int insertPos = findInsertPositionDeque(mainList, pendingElements[i], mainList.size() - 1);
        mainList.insert(mainList.begin() + insertPos, pendingElements[i]);
    }

    if (arr.size() % 2) 
    {
        int lastValue = arr.back();
        int insertPos = findInsertPositionDeque(mainList, lastValue, mainList.size() - 1);
        mainList.insert(mainList.begin() + insertPos, lastValue);
    }

    return mainList;
}
