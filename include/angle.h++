//
// Created by User on 16.03.2024.
//

#pragma once
#include <cmath>
#include "point.h++"
// Функция для вычисления угла между точками
double
angle(const Point& p1, const Point& p2)
{
    return atan2(p2.y - p1.y, p2.x - p1.x);
}