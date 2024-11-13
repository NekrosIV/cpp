/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:19:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/13 15:33:01 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook
{
  private:
	Contact contacts[8];
	int contactCount;
	std::string formatField(std::string field) const;

  public:
	PhoneBook();
	void addContact();
	void displayContacts() const;
};
