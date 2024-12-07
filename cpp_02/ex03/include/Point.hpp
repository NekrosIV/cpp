/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:23:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/07 15:03:39 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <Fixed.hpp>

class Point
{
  private:
	const Fixed x;
	const Fixed y;

  public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	Fixed getX() const;
	Fixed getY() const;
	~Point();
};

bool bsp(const Point &A, const Point &B, const Point &C, const Point &P);

