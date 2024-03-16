#include <iostream>
#include "include/item.h++"
#include "include/backpack.h++"
#if WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif
#define VER "0.1.0"

using namespace std;
int
main()
{
    Backpack bp(3);
#if WIN32
    // Установка кодировки для консоли Windows
    SetConsoleOutputCP(CP_UTF8);
#elif
    setlocale(LC_ALL, ".UTF-8");
#endif

    std::vector<Item> items = {{"PiSOS", 2, 12, 1}, {1, 10}, {3, 20},
        {2, 15}, {5, 150000},
        {"PiSOS2", 2, 15, 1}, {2, 15}};

    for (auto& item : items)
        bp.add(item);

    items.clear();
//    bp.print();


    while (true)
    {
#if WIN32
        std::system("cls");
#elif __linux__
        system("clear");
#endif
        cout << "Backpack v "
                VER
                "\n\n1.print"
                "\n2.all methods"
                "\n3.change items"
                "\n4.backpack size[" << bp.size() << "]" <<
             "\n6.exit"
             "";

        unsigned short mc = 0;
        std::cin >> mc;
#if WIN32
        std::system("cls");
//        HANDLE hStdout;
//
//        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
//
//        cls(hStdout);
#elif __linux__
        system("clear");
#endif
        switch (mc)
        {
            case 1:
            {
                bp.print();
                system("pause");
                break;
            }

            case 2:
            {
                bp.resize(4);
                cout << "Максимальная ценность предметов в рюкзаке(with_costs): " << bp.sort_with_costs() << endl;
                cout << "Максимальная ценность предметов в рюкзаке(lim)(bounded knapsack): " << bp.sort_lim() << endl;
                cout << "Максимальная ценность предметов в рюкзаке(unlim)(unbounded knapsack): " << bp.sort_unlim()
                     << endl;
                system("pause");
                break;
            }

            case 3:
            {
                unsigned int sw2 = 0;
//                cin >> sw2;
                while (sw2 != 6)
                {
#if WIN32
                    std::system("cls");
#elif __linux__
                    system("clear");
#endif
                    cout << "1.add new"
                            "\n2.change one"
                            "\n3.remove"
                            "\n6.exit";
                    cin >> sw2;
                    switch (sw2)
                    {
                        case 1:
                        {

                            break;
                        }

                        default:break;
                    }
                }
                break;
            }

            case 4:
            {
                unsigned int t = 0;
                cout << "size: ";
                cin >> t;
                bp.resize(t);
                break;
            }

            case 6:return 0;

            default: break;
        }
    }

    return 0;
}
