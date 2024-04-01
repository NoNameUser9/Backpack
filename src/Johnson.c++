//
// Created by User on 31.03.2024.
//

#include "../include/Johnson.h++"
int
main()
{
    std::vector<std::set<int>> universe = {{1, 2, 3, 4, 5}, {2, 5, 6}, {1, 3, 4}, {4, 5, 6}};
    std::vector<std::set<int>> subsets = {{1, 2, 3, 4}, {2, 3}, {1, 4, 6}, {3, 5}};

    std::set<int> result = setCover(universe, subsets);

    std::cout << "Selected subsets indices:";
    for (int subsetIndex : result)
        std::cout << " " << subsetIndex;

    std::cout << std::endl;

    return 0;
}