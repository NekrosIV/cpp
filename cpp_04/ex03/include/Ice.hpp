/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:57:05 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/03 17:02:30 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
  private:
	/* data */
  public:
	Ice();
	Ice(Ice const &other);
	Ice &operator=(Ice const &other);
	~Ice();
    
	AMateria *clone() const;
	void use(ICharacter &target);
};
