/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:31:27 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/09 14:34:55 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
  private:
  std::string name;
  Weapon &type;
  public:
	HumanA(std::string name, Weapon &type);
    void attack(void);
	~HumanA();
};
