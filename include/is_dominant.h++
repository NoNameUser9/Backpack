//
// Created by User on 16.03.2024.
//

#pragma once
#include "point.h++"
// Функция для определения того, является ли точка a доминантной по отношению к точке b
bool
is_dominant(const Point& a, const Point& b) { return (a.x >= b.x && a.y >= b.y) && (a.x > b.x || a.y > b.y); }