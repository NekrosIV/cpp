/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:25:37 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/06 13:53:31 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie
{
  private:
	std::string name;

  public:
	Zombie();
	void setName(std::string name);
	void announce(void);
	~Zombie();
};

Zombie	*zombieHorde(int N, std::string name);