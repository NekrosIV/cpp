/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:01:39 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/11 14:47:53 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name),
	_isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return(_name);
}

bool AForm::isSigned() const
{
    return(_isSigned);
}

int AForm::getSignGrade() const
{
    return(_signGrade);
}

int AForm::getExecGrade() const 
{
    return(_execGrade);
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high for the form!");
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low for the form!");
}

const char *AForm::FormNotSignedException::what() const throw() 
{ 
    return ("Error: Form is not signed!");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form \"" << form.getName() << "\" (Sign Grade: " << form.getSignGrade()
       << ", Exec Grade: " << form.getExecGrade() << ", Signed: "
       << (form.isSigned() ? "Yes" : "No") << ")";
    return os;
}