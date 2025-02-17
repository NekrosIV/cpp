/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:44:53 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/12 16:33:07 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fixedValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	fixedValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedValue);
}

void Fixed::setRawBits(int value)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedValue = value;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(fixedValue) / (1 << fractionalBits));
}

int Fixed::toInt() const
{
	return (fixedValue >> fractionalBits);
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixedValue = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->fixedValue > other.fixedValue);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->fixedValue < other.fixedValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->fixedValue >= other.fixedValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->fixedValue <= other.fixedValue);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->fixedValue == other.fixedValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->fixedValue != other.fixedValue);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(this->fixedValue + other.fixedValue);
	return (res);
}
Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(this->fixedValue - other.fixedValue);
	return (res);
}

// Fixed Fixed::operator*(const Fixed &other) const
// {
//     long long temp = static_cast<long long>(this->fixedValue) * other.fixedValue;
//     Fixed res;
//     res.fixedValue = static_cast<int>(temp >> fractionalBits);
//     return res;
// }
// Fixed Fixed::operator/(const Fixed &other) const
// {
//     if (other.fixedValue == 0)
//     {
//         std::cerr << "Division by zero" << std::endl;
//         return Fixed(0);
//     }
//     long long temp = (static_cast<long long>(this->fixedValue) << fractionalBits) / other.fixedValue;
//     Fixed res;
//     res.fixedValue = static_cast<int>(temp);
//     return res;
// }

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.fixedValue == 0)
	{
		std::cerr << "Division by zero" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++()
{
	fixedValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--()
{
	fixedValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
