//
// Created by User on 19.02.2024.
//

#pragma once
#include <ntdef.h>
#include <iostream>
#include <vector>
#include "item.h++"

class Backpack{
public:
	Backpack();
	explicit Backpack(unsigned size);
	void resize(unsigned size);
    [[maybe_unused]] [[nodiscard]] unsigned size() const;
    unsigned sort_with_costs();
    unsigned int
    sort_lim();
    unsigned sort_unlim();
    [[maybe_unused]] void print();
	void add(Item* item);

private:
    unsigned capacity_;
	std::vector<Item> items_;
};
