/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:19:09 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/10 17:54:42 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::incrementGrade()
{
    if(_grade - 1 < highestGrade)
        throw Bureaucrat::GradeTooHighException();
    
        _grade--;
}

void Bureaucrat::decrementGrade()
{
    if(_grade + 1 > lowestGrade)
		throw Bureaucrat::GradeTooLowException();
    
        _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: The grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: The grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
