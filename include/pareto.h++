//
// Created by User on 16.03.2024.
//

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "point.h++"
#include "is_dominant.h++"

class Pareto
{
public:
    class iterator;
    Pareto() = default;
    [[maybe_unused]]
    Pareto(std::vector<Point> points_in) : points(std::move(points_in)) {}

//    Pareto(iterator iterator);
    std::vector<Point>
    make()
    {
        // Вектор для хранения Парето-оптимальных точек
        std::vector<Point> paretoPoints;

        // Проходим по каждой точке и проверяем, является ли она Парето-оптимальной
        for (const auto& p1 : points)
        {
            bool isPareto = true;
            for (const auto& p2 : points)
                if (&p1 != &p2 && is_dominant(p2, p1))
                {
                    isPareto = false;
                    break;
                }

            if (isPareto)
                paretoPoints.push_back(p1);
        }

        // Вывод Парето-оптимальных точек
        std::cout << "Pareto Optimal Points:\n";
        for (const auto& p : paretoPoints)
            std::cout << "(" << p.x << ", " << p.y << ")\n";

        return paretoPoints;
    }

    iterator begin()
    {
        return points.begin();
    }

    // Метод end() для возвращения конечного итератора
    iterator
    end()
    {
        return points.end();
    }

    class iterator
    {
    public:
        iterator() = default;

        // Конструктор итератора
        [[maybe_unused]]
        iterator(std::vector<Point>::iterator ptr) : it_(ptr) {}

        // Оператор разыменования
        Point&
        operator*()
        {
            return *it_;
        }

        // Оператор инкремента префиксного
        iterator&
        operator++()
        {
            ++it_;
            return *this;
        }

        // Оператор равенства
        bool
        operator!=(const iterator& other) const
        {
            return it_ != other.it_;
        }

    private:
        std::vector<Point>::iterator it_;
    };
private:
    std::vector<Point> points;
};