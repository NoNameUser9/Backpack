//
// Created by User on 19.02.2024.
//

#pragma once

#include <string>
#include <utility>
struct Item
{
	Item(){
		cost = 0;
		weight = 0;
	}

	Item(unsigned int weight, unsigned int cost){
		this->cost = cost;
		this->weight = weight;
	}

	Item(std::string content, unsigned int weight, unsigned int cost){
		this->content = std::move(content);
		this->cost = cost;
		this->weight = weight;
	}

	std::string content;
	unsigned int weight;
	unsigned int cost;
};
