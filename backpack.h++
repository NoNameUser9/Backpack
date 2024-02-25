//
// Created by User on 19.02.2024.
//

#pragma once
#include "Item.h++"
int n = 3; //число строк = число вещей
int k = 4; //грузоподъёмность рюкзака
//массив вещей
Item items;
//массив промежуточных состояний рюкзака

class Backpack{
	Backpack() {
		size_ = 0;
		item_ = nullptr;
	};

	Backpack(unsigned int size, Item* item){
		size_ = size;
		item_ = new Item[size_];
	}

	void resize(unsigned int size){
		Item* item;
		memcpy(item, item_, sizeof(int) * size_);
		item_ = new Item[size];
		memcpy(item_, item, sizeof(int) * size_);
		size_ = size;
	}

	[[nodiscard]] unsigned size() const{
		return size_;
	}

	void add(Item* item){

	}

private:
	unsigned int size_;
	Item* item_;
};

void foo(){
items.weight;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < k + 1; j++) {
			if (i == 0 || j == 0) { //нулевую строку и столбец заполняем нулями
				bp[i][j] = new Backpack(new Item[]{}, 0);
			} else if (i == 1) {
				/*первая строка заполняется просто: первый предмет кладём или не кладём в зависимости от веса*/
				bp[1][j] = items[0].getWeight() <= j ? new Backpack(new Item[]{items[0]}, items[0].getPrice())
					: new Backpack(new Item[]{}, 0);
			} else {
				if (items[i - 1].getWeight() > j) //если очередной предмет не влезает в рюкзак,
					bp[i][j] = bp[i - 1][j];    //записываем предыдущий максимум
				else {
					/*рассчитаем цену очередного предмета + максимальную цену для (максимально возможный для рюкзака вес − вес предмета)*/
					int newPrice = items[i - 1].getPrice() + bp[i - 1][j - items[i - 1].getWeight()].getPrice();
					if (bp[i - 1][j].getPrice() > newPrice) //если предыдущий максимум больше
						bp[i][j] = bp[i - 1][j]; //запишем его
					else {
						/*иначе фиксируем новый максимум: текущий предмет + стоимость свободного пространства*/
						bp[i][j] = new Backpack(Stream.concat(Arrays.stream(new Item[]{items[i - 1]}),
															  Arrays.stream(bp[i - 1][j - items[i - 1].getWeight()].getItems())).toArray(Item[]::new), newPrice);
					}
				}
			}
		}
	}
}
