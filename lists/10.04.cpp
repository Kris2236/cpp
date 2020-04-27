/*4. Dana jest niepusta lista reprezentująca liczbę naturalną. Kolejne elementy listy przechowują kolejne cyfry. Proszę napisać funkcję zwiększającą taką liczbę o 1.	*/

#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node* last;
};

void print(Node* node)
{
	while (node != nullptr)
	{
		cout << node->val;
		node = node->next;
	}
	cout << "\n";
}

void insert(Node* node, int val)
{
	Node* newElement = new Node;
	newElement->val = val;
	newElement->next = nullptr;

	while (node->next != 0)
		node = node->next;

	node->next = newElement;
	newElement->last = node;

}

void add1(Node* node)
{
	while (node->next != nullptr)
		node = node->next;

	if (node->val == 9)
	{
		bool flag = false;

		while (node->last != nullptr && node->val == 9 && ! flag)
		{
			node->val = 0;
			if (node->last->val != 9)
			{
				node->last->val += 1;
				flag = true;
			}

			node = node->last;
		}

		if (node->last == nullptr && node->val == 9)		//problem 89->100!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		{
			Node* tmp = node;
			bool flaga = false;

			while (tmp->next != 0)
			{
				tmp = tmp->next;
				if (tmp->val != 9)
					flaga = true;
			}

			if (!flaga)
			{
				node->val = 1;
				insert(node, 0);	//dodanie nowego 0 do liczby
			}
		}
	}
	else
	{
		node->val += 1;
	}
}

int main()
{
	Node* node = new Node;
	node->next = nullptr;
	node->val = 1;
	node->last = nullptr;

	insert(node, 8);
	print(node);

	for (int i = 0; i < 100; i++)
	{
		add1(node);
		print(node);
	}

}