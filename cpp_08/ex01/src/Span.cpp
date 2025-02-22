/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:13:06 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/22 16:37:42 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "color.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &other) : _n(other._n), _tab(other._tab)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_n = other._n;
		_tab = other._tab;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (_tab.size() >= _n)
		throw std::overflow_error("Span is full, cannot add more numbers.");
	_tab.push_back(n);
}

int Span::shortestSpan() const
{
	if (_tab.size() < 2)
		throw std::length_error("Not enough numbers to find a span.");

	std::vector<int> sorted = _tab;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (unsigned int i = 1; i < sorted.size() - 1; i++)
	{
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int Span::longestSpan() const
{
	if (_tab.size() < 2)
		throw std::length_error("Not enough numbers to find a span.");

	int minVal = *std::min_element(_tab.begin(), _tab.end());
	int maxVal = *std::max_element(_tab.begin(), _tab.end());

	return (maxVal - minVal);
}

void Span::addRange(std::vector<int>::iterator begin,
	std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > static_cast<int>(_n - _tab.size()))
		throw std::overflow_error("Not enough space to add range of numbers.");
	_tab.insert(_tab.end(), begin, end);
}
