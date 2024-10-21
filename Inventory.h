#pragma once
#include "Item.h"
#include <iostream>
#include <vector>
enum Way
{
	ascending,
	descending
};

class Inventory
{
public:
	Inventory(std::vector<Item*>& items);
	~Inventory();

	void Print();

	void AddItem(Item* item);
	void DeleteItem(const char* itemName);
	Item* DisplayItemDetail(Item* item);
	void SortByName();
	void SortByWeight(int way);


	void SetItemVector(std::vector<Item*>& items) { m_itemsVector = items; }
	std::vector<Item*>* GetItemVector() { return &m_itemsVector; };
private:
	std::vector<Item*> m_itemsVector;
};

