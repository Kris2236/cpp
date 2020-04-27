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

Node* conect(Node* node_p, Node* node_np)		//źle łączy listy
{
	Node* head;
	Node* tail;

	if (node_p->val > node_np->val)
	{
		head = node_np;
		tail = head;
		node_np = node_np->next;
	}
	else
	{
		head = node_p;
		tail = head;
		node_p = node_p->next;
	}

	while (node_p != nullptr && node_np != nullptr)
	{
		if (node_p->val > node_np->val)
		{
			tail->next = node_p;
			tail = node_p;
			node_p = node_p->next;
		}
		else
		{
			tail->next = node_np;
			tail = node_np;
			node_np = node_np->next;
		}

		print(head);
	}

	if (node_p != nullptr)
	{
		tail->next = node_p;
	}

	if (node_np != nullptr)
	{
		tail->next = node_np;
	}

	print(head);

	return head;
}

void sort(Node* node) {

	Node* tmp = node;
	Node* node_p = new Node;
	Node* node_np = new Node;

	node_p->next = nullptr;
	node_np->next = nullptr;

	node_p->val = -1;
	node_np->val = -1;


	while (tmp != nullptr)
	{
		if (tmp->val % 2 == 0)
			insert(node_p, tmp->val);
		else if (tmp->val % 2 == 1)
			insert(node_np, tmp->val);

		tmp = tmp->next;
	}
	print(node_p->next->next);
	print(node_np->next);

	tmp = conect(node_p->next->next, node_np->next);
	print(tmp);

}

int main()
{
	Node* node = new Node;
	node->val = 0;
	node->next = nullptr;

	for (int i = 1; i < 7; i++)
	{
		insert(node, i);
		print(node);
	}

	sort(node);
}