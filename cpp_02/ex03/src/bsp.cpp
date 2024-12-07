/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:28:51 by kasingh           #+#    #+#             */
/*   Updated: 2024/12/07 15:02:38 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static Fixed getSignedArea(const Point &A, const Point &B, const Point &C)
{
    // area = xA(yB - yC) + xB(yC - yA) + xC(yA - yB)
    Fixed termA = A.getX() * (B.getY() - C.getY());
    Fixed termB = B.getX() * (C.getY() - A.getY());
    Fixed termC = C.getX() * (A.getY() - B.getY());
    Fixed totalArea = termA + termB + termC;
    return totalArea;
}

bool bsp(const Point &A, const Point &B, const Point &C, const Point &P)
{

    Fixed originalArea = getSignedArea(A, B, C).abs();
    Fixed areaPBC = getSignedArea(P, B, C).abs();
    Fixed areaPAC = getSignedArea(A, P, C).abs();
    Fixed areaPAB = getSignedArea(A, B, P).abs();
    return (originalArea == (areaPBC + areaPAC + areaPAB));
}
