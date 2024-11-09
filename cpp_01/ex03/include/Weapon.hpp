/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:19:25 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/07 13:42:56 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
  private:
	std::string type;

  public:
	Weapon(std::string initialType);
	void setType(std::string value);
	const std::string &getType() const;
	~Weapon();
};
