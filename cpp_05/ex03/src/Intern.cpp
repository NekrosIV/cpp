/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:47:55 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/12 13:04:54 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
AForm *Intern::createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}
AForm *Intern::createPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*formCreators[])(const std::string &) = {
        &Intern::createShrubbery,
		&Intern::createRobotomy, 
        &Intern::createPardon};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "✅ Intern creates " << formName << std::endl;
			return (formCreators[i](target));
		}
	}
	std::cerr << "❌ Error: Unknown form type '" << formName << "'" << std::endl;
	return (NULL);
}
