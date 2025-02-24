/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:59:16 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/17 17:16:46 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> 
void swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> 
T min(const T &a, const T &b)
{
	if (a < b)
		return (a);

	return (b);
}
template <typename T> 
T max(const T &a, const T &b)
{
	if (a > b)
		return (a);

	return (b);
}