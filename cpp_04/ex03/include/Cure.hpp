/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:23:15 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/03 17:24:00 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
  private:
	/* data */
  public:
	Cure();
	Cure(Cure const &other);
	Cure &operator=(Cure const &other);
	~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);
};