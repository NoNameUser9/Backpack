#include <iostream>
#include "item.h++"
#include "backpack.h++"

int
main()
{
    Backpack bp(3);
    setlocale(LC_ALL, "rus");

    std::vector<Item> items = {{"PiSOS", 2, 12, 1}, {1, 10}, {3, 20},
                               {2, 15}, {5, 150000},
                               {"PiSOS2", 2, 15, 1}, {2, 15}};

    for(auto & item : items)
        bp.add(new Item(item.content, item.weight, item.cost, item.quantity));

    bp.resize(4);
    bp.print();

    std::cout << "Максимальная ценность предметов в рюкзаке(with_costs): " << bp.sort_with_costs() << std::endl;
    std::cout << "Максимальная ценность предметов в рюкзаке(lim)(bounded knapsack): " << bp.sort_lim() << std::endl;
    std::cout << "Максимальная ценность предметов в рюкзаке(unlim)(unbounded knapsack): " << bp.sort_unlim() << std::endl;

	return 0;
}
