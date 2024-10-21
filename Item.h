#pragma once
struct ITEMDETAIL
{
	const char* name;
	int weight;
};

class Item
{
public:
	Item(const char* name, int weight);
	~Item();

	void Print();

	ITEMDETAIL* GetDetails() { return m_pItemDetail; }
	void SetDetails(ITEMDETAIL* itemDetail) { m_pItemDetail = itemDetail; }

private:
	ITEMDETAIL* m_pItemDetail;
};

