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

	std::string content;
	unsigned int weight;
	unsigned int cost;
};
