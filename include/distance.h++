//
// Created by User on 16.03.2024.
//

#pragma once
#include <cmath>
#include "point.h++"
// Функция для вычисления расстояния между точками
double
distance(const Point& p1, const Point& p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}