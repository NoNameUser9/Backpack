#include <iostream>
#include "item.h++"
#include "backpack.h++"

int
main()
{
    Backpack bp(3);
    setlocale(LC_ALL, "rus");

    std::vector<Item> items = {{"PiSOS", 2, 12}, {1, 10}, {3, 20},
                               {2, 15}, {5, 150000}, {"PiSOS2", 2, 15},
                               {2, 15}};

    for(auto & item : items)
        bp.add(new Item(item.content, item.weight, item.cost));

    bp.resize(4);
    bp.print();

    std::cout << "������������ �������� ��������� � �������: " << bp.sort_unlim() << std::endl;
    std::cout << "������������ �������� ��������� � �������: " << bp.sort_lim(1) << std::endl;

	return 0;
}
