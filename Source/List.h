#pragma once

template<typename A>
class Item
{
public:
	A Data;
	Item* pNext;
public:
	Item(Item* pNext = nullptr) : pNext(pNext)
	{
	}
	Item(A Data, Item* pNext = nullptr) : Data(Data), pNext(pNext)
	{
	}
	~Item()
	{
	}
};

template<typename B>
class List
{
public:
	List():m_head(nullptr)
	{

	}
	~List()
	{

	}
	//Adding elements to list:
	void push_front(B Data)
	{
		Item<B>* item = new Item<B>(Data, nullptr);
		item->pNext = m_head;
		m_head = item;
	}

	void push_back(B Data)
	{
		Item<B>* last = m_head;
		while (last->pNext != nullptr)
		{
			last = last->pNext;
		}
		last->pNext = new Item<B>(Data, nullptr);
	}
	//Removeing elements from list
	void pop_front()
	{
		if (m_head)
		{
			Item<B> *new_head = m_head->pNext;
			delete m_head;
			m_head = new_head;
		}
	}

	void pop_back()
	{
		if (m_head)
		{
			Item<B>* last = m_head;
			Item<B>* new_last = last;
			while (last->pNext != nullptr)
			{
				new_last = last;
				last = last->pNext;
			}
			new_last->pNext = nullptr;
			delete last;
		}
	}

	//Aux method with cout:
	/*void Print()
	{
		Item<B> *print = m_head;
		for (int i = 1; print != nullptr; i++)
		{
			cout << i << "\t" << print->Data << "\n";
			print = print->pNext;
		}
	}
	*/
private:
	Item<B>* m_head;
};
