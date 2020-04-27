/*       Dana jest niepusta lista, proszę napisać funkcję usuwającą co drugi element listy. Do funkcji należy przekazać wskazanie na pierwszy element listy.       */

#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};

void print(Node* node)
{
	while (node != nullptr)
	{
		cout << node->val << "\t";
		node = node->next;
	}
	cout << "\n";
}

void deleteLast(Node*& node, Node*& last)
{
	node = last->next;
	last->next = nullptr;
	delete node;
}

void deleteMiddle(Node* node, Node* last)
{
	node = last->next;
	last->next = node->next;
	delete node;
}

void delete_even(Node* node)
{
	if (node == nullptr)	return;		//spr czy lista jest pusta

	int i = 0;
	Node* tmp = node;
	Node* last = nullptr;

	while (tmp != nullptr)
	{
		i++;		//licznik gdy pażysty usówa lelment, w pierwszej iteracji ustawiony na 1 => pierwszy element nie zostanie usunięty
		cout << "I = " << i << "\tDELETE: " << i / 2 << endl;

		if (i % 2 == 0 && tmp->next == nullptr || (i >= 5))
		{
			//deletelast(tmp, last);
			return;
		}

		if (i % 2 == 0)
		{
			deleteMiddle(tmp, last);		//błąd przed drugim wykonaniem

		}
		else
		{
			last = tmp;
			tmp = tmp->next;
		}

		//print(tmp);

	}
}

void insert(Node* node, int val)
{
	Node* newElement = new Node;
	newElement->val = val;
	newElement->next = nullptr;
	
	while (node->next != 0)
		node = node->next;

	node->next = newElement;
}

int main()
{
	Node* node = new Node;
	node->next = nullptr;
	node->val = 1;

	insert(node, 2);
	insert(node, 3);
	insert(node, 4);
	insert(node, 5);
	insert(node, 6);

	print(node);

	delete_even(node);
	print(node);
}