//
// Created by User on 19.02.2024.
//

#include "item.h++"
Item::Item()
{
    weight = 0,	cost = 0;
}

Item::Item(unsigned int weight, unsigned int cost)
{
    this->cost = cost;
    this->weight = weight;
}

Item::Item(std::string content, unsigned int weight, unsigned int cost)
{
    this->content = std::move(content);
    this->cost = cost;
    this->weight = weight;
}
Item::Item(std::string content, unsigned int weight, unsigned int cost, unsigned int quantity)
{
    this->content = std::move(content);
    this->cost = cost;
    this->weight = weight;
    this->quantity = quantity;
}
