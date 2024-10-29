/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:19:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/10/29 17:17:30 by kasingh          ###   ########.fr       */
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
	void addContact(const Contact &newContact);
	void displayContacts() const;
};
