/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:19:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/01 14:49:13 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook
{
  private:
	Contact contacts[8];
	int contactCount;

  public:
	PhoneBook();
	void addContact();
	void displayContacts() const;
	std::string formatField(std::string field) const;
};
