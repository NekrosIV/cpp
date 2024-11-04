/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:19:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/04 14:44:56 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string darkestSecret;
	std::string phoneNumber;

  public:
	bool add();
	bool isAlpha(std::string input);
	bool isDigits(std::string input);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	void print() const;
};
