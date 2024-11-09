/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:49:01 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/09 14:51:44 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
  private:
	std::string name;
	Weapon *type;

  public:
	HumanB(std::string name);
	void setWeapon(Weapon &type);
	void attack(void);
	~HumanB();
};
