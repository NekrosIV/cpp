/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:59:16 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/17 17:23:42 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T, typename func> 
void iter(T* a, int len, func funtion)
{
	for (int i = 0; i < len; i++)
		funtion(a[i]);
}