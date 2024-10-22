#pragma once
#include "Item.h"
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

enum Way
{
	ASCENDING,
	DESCENDING
};

enum Filters
{
	WEIGHT_EQ,
	WEIGHT_LT,
	WEIGHT_GT,
	NAME_CONTAINS,
	NAME_BW,
	NAME_EW
};

class Inventory
{
public:
	Inventory(std::vector<Item*>& items, int maxCapacity);
	Inventory();
	~Inventory();

	void Print();

	void AddItem(Item* item);
	void DeleteItem(const char* itemName);
	Item* DisplayItemDetail(Item* item);
	void SortByName();
	void SortByWeight(int way);
	int AverageItemWeight();
	int TotalItemWeight();
	int AmountItemHeavierThan(int weight);

	void Filter(std::function<bool(Item*)> lambda)
	{
		Inventory* pInv = new Inventory();
		std::copy_if(m_itemsVector.begin(), m_itemsVector.end(), std::back_inserter(pInv->m_itemsVector), lambda);
		std::cout << "With this filter, ";
		pInv->Print();
	}

	void SetItemVector(std::vector<Item*>& items) { m_itemsVector = items; }
	std::vector<Item*>* GetItemVector() { return &m_itemsVector; };

private:
	std::vector<Item*> m_itemsVector;
	int m_maxCapacity;
	int m_currentWeight = 0;
};


