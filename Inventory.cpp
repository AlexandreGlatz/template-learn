#include "Inventory.h"
#include <algorithm>

Inventory::Inventory(std::vector<Item*>& items) : m_itemsVector(items)
{
}

Inventory::~Inventory()
{
	m_itemsVector.clear();
}

void Inventory::Print()
{
	std::cout << "Inventory contains : " << std::endl;

	for (int i = 0; i < m_itemsVector.size(); i++)
		m_itemsVector[i]->Print();

	std::cout << std::endl;
}

void Inventory::AddItem(Item* item)
{
	m_itemsVector.push_back(item);
}

void Inventory::DeleteItem(const char* itemName) //#TODO enum to choose
{
	bool found = false;
	for (int i = 0; i < m_itemsVector.size(); i++)
	{
		if (m_itemsVector[i]->GetDetails()->name == itemName)
		{
			m_itemsVector.erase(m_itemsVector.begin() + i);
			std::cout << itemName << " found and removed from inventory successfully" << std::endl;
			bool found = true;
			return;
		}

		else if (i == m_itemsVector.size() - 1 && found == false)
		{
			std::cout << "Item " << itemName << " not found in inventory, could not delete it" << std::endl;
		}
	}
}

Item* Inventory::DisplayItemDetail(Item* item)
{
	auto it = std::find(m_itemsVector.begin(), m_itemsVector.end(), item);
	if (it == m_itemsVector.end())
	{
		std::cout << "Could not display item details, item :" << item->GetDetails()->name << " not found in inventory" << std::endl;
		return nullptr;
	}

	std::cout << "item : " << item->GetDetails()->name << "found for display" << std::endl;
	std::cout << "name : " << item->GetDetails()->name << ", weight : " << item->GetDetails()->weight << std::endl;
}

void Inventory::SortByName()
{
	std::sort(m_itemsVector.begin(), m_itemsVector.end(), [&](Item* item1, Item* item2)
		{
			if (item1->GetDetails()->name == item2->GetDetails()->name)
				return false;

			int index = 0;
			size_t size1 = sizeof(item1->GetDetails()->name) / sizeof(*item1->GetDetails()->name);

			while (index < size1 && item1->GetDetails()->name[index] == item2->GetDetails()->name[index])
				index++;

			return item1->GetDetails()->name[index] < item2->GetDetails()->name[index];
		});
}

void Inventory::SortByWeight(int way)
{
	switch (way) 
	{
	case ASCENDING:
		std::sort(m_itemsVector.begin(), m_itemsVector.end(), [&](Item* item1, Item* item2)
			{
				return item1->GetDetails()->weight < item2->GetDetails()->weight;
			});
		break;

	case DESCENDING:
		std::sort(m_itemsVector.begin(), m_itemsVector.end(), [&](Item* item1, Item* item2)
			{
				return item1->GetDetails()->weight > item2->GetDetails()->weight;
			});
		break;
	}
}


void Inventory::Filter(int filter, int arg)
{
	switch (filter)
	{
	case WEIGHT_EQ:
		for (int i = 0; i < m_itemsVector.size(); i++)
		{
			if (m_itemsVector[i]->GetDetails()->weight == arg)
				m_itemsVector[i]->Print();
		}
		break;

	case WEIGHT_LT:
		for (int i = 0; i < m_itemsVector.size(); i++)
		{
			if (m_itemsVector[i]->GetDetails()->weight < arg)
				m_itemsVector[i]->Print();
		}
		break;

	case WEIGHT_GT:
		for (int i = 0; i < m_itemsVector.size(); i++)
		{
			if (m_itemsVector[i]->GetDetails()->weight > arg)
				m_itemsVector[i]->Print();
		}
		break;

	case NAME_BW:
		for (int i = 0; i < m_itemsVector.size(); i++)
		{
			if (m_itemsVector[i]->GetDetails()->name[0] == arg)
				m_itemsVector[i]->Print();
		}
		break;

	case NAME_EW:
		for (int i = 0; i < m_itemsVector.size(); i++)
		{
			if (m_itemsVector[i]->GetDetails()->name[sizeof(m_itemsVector[i]->GetDetails()->name) / sizeof(*m_itemsVector[i]->GetDetails()->name)] == arg)
				m_itemsVector[i]->Print();
		}
		break;
	}
}




