//
// Created by User on 16.03.2024.
//

#pragma once
//#include <matplotlibcpp.h>
#include <vector>
#include <algorithm>
#include "point.h++"
#include "is_dominant.h++"
#include "distance.h++"
#include "angle.h++"

// Алгоритм обертки Грэхема для построения выпуклой оболочки
std::vector<Point> convex_hull(std::vector<Point> points) {
    int n = points.size();
    if (n < 3) return {};

    std::swap(points[0], *std::min_element(points.begin(), points.end(),
                                           [](const Point& a, const Point& b) {
                                               return a.y == b.y ? a.x < b.x : a.y < b.y;
                                           }));

    Point pivot = points[0];
    std::sort(points.begin() + 1, points.end(), [pivot](const Point& a, const Point& b) {
        double angle_a = angle(pivot, a);
        double angle_b = angle(pivot, b);
        if (angle_a == angle_b) {
            return distance(pivot, a) < distance(pivot, b);
        }
        return angle_a < angle_b;
    });

    std::vector<Point> hull = {points[0], points[1]};
    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && !is_dominant(hull[hull.size() - 2], hull[hull.size() - 1]) && is_dominant(hull.back(), points[i])) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}
