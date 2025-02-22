/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:07:39 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/22 16:50:20 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

class Span
{
  private:
	unsigned int _n;
	std::vector<int> _tab;

  public:
	Span();
	Span(unsigned int _n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
