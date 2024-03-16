//
// Created by User on 16.03.2024.
//

#include <chrono>
#include <matplotlibcpp.h++>
#include "../include/pareto.h++"
#include "../include/graham_convex_hull.h++"

namespace plt = matplotlibcpp;

int
main()
{
    std::srand(std::chrono::system_clock::now().time_since_epoch().count());
    int n = rand() % 20;

    std::vector<Point> points;
    for(int i = 0; i < n; ++i)
        points.push_back(Point(rand()%15,rand()%15));

//    Pareto p(points);
    double pause_interval = 0.1;

    std::vector<Point> pareto_points;
    for (const auto& p1 : points)
    {
        bool is_pareto = true;
        for (const auto& p2 : points)
            if (&p1 != &p2 && is_dominant(p2, p1))
            {
                is_pareto = false;
                break;
            }

        if (is_pareto)
            pareto_points.push_back(p1);
    }

//    Pareto pp(pareto_points);

    std::vector<Point> hull = convex_hull(pareto_points);
//    for (auto it = p.begin(); it != p.end(); ++it)
//    {
    std::cout << "\nDebug messages:\n";
    std::vector<double> x, y;
    for (const auto& point : points)
    {
        x.push_back(point.x);
        y.push_back(point.y);
        plt::clf();
        plt::plot(x, y, "bo"); // Все точки на графике в синем цвете

        plt::xlabel("X");
        plt::ylabel("Y");
        plt::title("Pareto Optimal Points with Convex Hull Boundary (Graham's Scan)");
        plt::pause(pause_interval);
    }
    std::cout << "points are drawn\n";

    std::vector<double> pareto_x, pareto_y;
    for (const auto& point : pareto_points)
    {
        pareto_x.push_back(point.x);
        pareto_y.push_back(point.y);

        plt::clf();
        plt::plot(x, y, "bo"); // Все точки на графике в синем цвете
        plt::plot(pareto_x, pareto_y, "ro"); // Парето-оптимальные точки в красном цвете

        plt::xlabel("X");
        plt::ylabel("Y");
        plt::title("Pareto Optimal Points with Convex Hull Boundary (Graham's Scan)");
        plt::pause(pause_interval);
    }
    std::cout << "pareto completed\n";


    std::vector<double> hull_x, hull_y;
    for (const auto& point : hull)
    {
        hull_x.push_back(point.x);
        hull_y.push_back(point.y);

        plt::clf();
        plt::plot(x, y, "bo"); // Все точки на графике в синем цвете
        plt::plot(pareto_x, pareto_y, "ro"); // Парето-оптимальные точки в красном цвете
        plt::plot(hull_x, hull_y, "g-"); // Граница выпуклой оболочки в зеленом цвете

        plt::xlabel("X");
        plt::ylabel("Y");
        plt::title("Pareto Optimal Points with Convex Hull Boundary (Graham's Scan)");
        plt::pause(pause_interval);
    }
    std::cout << "pareto hull are drawn\n";
//    }
    plt::show();

    return 0;
}