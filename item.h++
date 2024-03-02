//
// Created by User on 19.02.2024.
//

#pragma once

#include <string>
#include <utility>

struct Item
{
	Item();
    Item(unsigned int weight, unsigned int cost);
    Item(std::string content, unsigned int weight, unsigned int cost);
    Item(std::string content, unsigned int weight, unsigned int cost, unsigned quantity);

	std::string content;
	unsigned int weight = 0;
	unsigned int cost = 0;
	unsigned int quantity = 0;
};
