//
// Created by User on 19.02.2024.
//

#include "../include/item.h++"
Item::Item()
{
    weight = 0, cost = 0;
}

Item::Item(const unsigned int& weight, const unsigned int& cost)
{
    this->cost = cost;
    this->weight = weight;
}

Item::Item(const std::string& content, const unsigned int& weight, const unsigned int& cost)
{
    this->content = content;
    this->cost = cost;
    this->weight = weight;
}

Item::Item(const std::string& content, const unsigned int& weight, const unsigned int& cost, const unsigned int& quantity)
{
    this->content = content;
    this->cost = cost;
    this->weight = weight;
    this->quantity = quantity;
}
