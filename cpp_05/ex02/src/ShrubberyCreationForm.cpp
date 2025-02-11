/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:53:03 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/11 17:32:06 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target,
	145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream file((getName() + "_shrubbery").c_str());

    if (!file) {
        std::cerr << "❌ Error: Unable to create file!" << std::endl;
        return;
    }

    file << "       🌳       \n";
    file << "      🌲🌲      \n";
    file << "     🌳🌳🌳     \n";
    file << "    🌲🌲🌲🌲    \n";
    file << "   🌳🌳🌳🌳🌳   \n";
    file << "      |  |       \n";

    file.close();
    std::cout << "✅ File \"" << getName() << "_shrubbery\" created successfully!" << std::endl;
}