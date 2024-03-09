//
// Created by User on 19.02.2024.
//

#pragma once
#include <iostream>
#include <vector>
#include "item.h++"

class Backpack
{
public:
    Backpack();
    explicit Backpack(const unsigned int& size);

    void
    resize(const unsigned int& size);

    [[maybe_unused]] [[nodiscard]] unsigned int
    size() const;

    unsigned int
    sort_with_costs();

    unsigned int
    sort_lim();

    unsigned int
    sort_unlim();

    [[maybe_unused]] void
    print();

    void
    add(const Item& item);

private:
    unsigned int capacity_;
    std::vector<Item> items_;
};
