/*5. Proszę napisać funkcję, która rozdziela elementy listy wejściowej do 10
list, według ostatniej cyfry pola val. W drugim kroku powstałe listy należy
połączyć w jedną listę, która jest posortowana niemalejąco według ostatniej
cyfry pola val.
*/

#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};

struct data {
	Node* head;
};

void print(Node* node)
{
	while (node != nullptr)
	{
		cout << node->val << "\t";
		node = node->next;
	}
	cout << endl;
}

void insert(Node* node, int val)
{
	if (node == nullptr)
		return;

	Node* newElement = new Node;
	newElement->val = val;
	newElement->next = nullptr;

	while (node->next != nullptr)
	{
		node = node->next;
	}

	node->next = newElement;
}

Node* rek(Node* left, Node* right)
{
	if (left == NULL && right == NULL)
		return NULL;
	if (left != NULL)
		return left;
	if (right != NULL)
		return right;

	if (left->val < right->val)
	{
		left->next = rek(left->next, right);
		return left;
	}
	else
	{
		right->next = rek(left, right->next);
		return right;
	}
}

void sort(Node* node) {

	Node* tmp = node;
	Node* node_0 = new Node;
	Node* node_1 = new Node;
	Node* node_2 = new Node;
	Node* node_3 = new Node;
	Node* node_4 = new Node;
	Node* node_5 = new Node;
	Node* node_6 = new Node;
	Node* node_7 = new Node;
	Node* node_8 = new Node;
	Node* node_9 = new Node;
	node_0->next = nullptr;
	node_1->next = nullptr;
	node_2->next = nullptr;
	node_3->next = nullptr;
	node_4->next = nullptr;
	node_5->next = nullptr;
	node_6->next = nullptr;
	node_7->next = nullptr;
	node_8->next = nullptr;
	node_9->next = nullptr;
	node_0->val = -1;
	node_1->val = -1;
	node_2->val = -1;
	node_3->val = -1;
	node_4->val = -1;
	node_5->val = -1;
	node_6->val = -1;
	node_7->val = -1;
	node_8->val = -1;
	node_9->val = -1;

	while (tmp != nullptr)
	{
		if (tmp->val % 10 == 0)
			insert(node_0, tmp->val);
		else if (tmp->val % 10 == 1)
			insert(node_1, tmp->val);
		else if (tmp->val % 10 == 2)
			insert(node_2, tmp->val);
		else if (tmp->val % 10 == 3)
			insert(node_3, tmp->val);
		else if (tmp->val % 10 == 4)
			insert(node_4, tmp->val);
		else if (tmp->val % 10 == 5)
			insert(node_5, tmp->val);
		else if (tmp->val % 10 == 6)
			insert(node_6, tmp->val);
		else if (tmp->val % 10 == 7)
			insert(node_7, tmp->val);
		else if (tmp->val % 10 == 8)
			insert(node_8, tmp->val);
		else if (tmp->val % 10 == 9)
			insert(node_9, tmp->val);

		tmp = tmp->next;
	}
	print(node_0);
	print(node_1);
	print(node_2);
	print(node_3);
	print(node_4);
	print(node_5);
	print(node_6);
	print(node_7);
	print(node_8);
	print(node_9);

	tmp = rek(node_0->next, node_9->next);		//nie działa łączenie list
	print(tmp);
	
}

int main()
{
	Node* node = new Node;
	node->val = 0;
	node->next = nullptr;

	for (int i = 1; i < 15; i++)
	{
		insert(node, i);
		print(node);
	}

	sort(node);
}