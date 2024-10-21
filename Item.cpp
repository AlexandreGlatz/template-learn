#include "Item.h"
#include <iostream>
Item::Item(const char* name, int weight)
{
	m_pItemDetail->name = name;
	m_pItemDetail->weight = weight;
}

Item::~Item()
{
	m_pItemDetail = nullptr;
}

void Item::Print()
{
	std::cout << m_pItemDetail->name << " (Poids : " << m_pItemDetail->weight << " ) ";
}