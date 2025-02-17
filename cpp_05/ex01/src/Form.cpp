/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:01:39 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/11 14:26:51 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name),
	_isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return(_name);
}

bool Form::isSigned() const
{
    return(_isSigned);
}

int Form::getSignGrade() const
{
    return(_signGrade);
}

int Form::getExecGrade() const 
{
    return(_execGrade);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _signGrade)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high for the form!");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low for the form!");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form \"" << form.getName() << "\" (Sign Grade: " << form.getSignGrade()
       << ", Exec Grade: " << form.getExecGrade() << ", Signed: "
       << (form.isSigned() ? "Yes" : "No") << ")";
    return os;
}