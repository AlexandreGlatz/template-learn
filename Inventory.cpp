#include "Inventory.h"

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

		else if (i == m_itemsVector.size() && found == false)
		{
			std::cout << "Could not delete item, item :" << itemName << " not found in inventory" << std::endl;
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
	
}



