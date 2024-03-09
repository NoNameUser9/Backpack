//
// Created by User on 19.02.2024.
//

#pragma once

#include <string>
#include <utility>

struct Item
{
    Item();
    Item(const unsigned int& weight, const unsigned int& cost);
    Item(const std::string& content, const unsigned int& weight, const unsigned int& cost);
    Item(const std::string& content, const unsigned int& weight, const unsigned int& cost, const unsigned int& quantity);

    Item&
    operator=(const Item& r) = default;

    std::string content;
    unsigned int weight = 0;
    unsigned int cost = 0;
    unsigned int quantity = 0;
};
