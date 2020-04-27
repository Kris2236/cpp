// z wartownikiem
/*1. Zaimplementuj zbiór mnogościowy liczb naturalnych korzystając ze struktury listy.
- czy element należy do zbioru	+
- dodanie elementu do zbioru	+
- usunięcie elementu ze zbioru	+		*/

#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
	Node* last;
};

struct Data {		//JAK WPISAĆ ADRES PIERWSZEGO DO STRUKTURY
	Node* head;
	Node* tail;
	int elements;
};

void print(Node* node)
{
	node = node->next;
	while (node != nullptr)
	{
		cout << node->value << "  " << "[" << node <<"]" <<"\t";
		node = node->next;
	}
	cout << endl << endl;
}

void insertMidleValue(Node* node)
{
	int value, value2;
	cout << "Podaj wartosc elementu po ktorym chcesz wstawic nowy: ";	cin >> value;
	cout << "Podaj wartosc nowego elementu";							cin >> value2;

	node = node->next;		//wartownik

	while (node != nullptr)
	{
		if (node->value == value)
		{
			/*Node* newElement = new Node;
			newElement->value = value2;
			newElement->last = node->last;
			newElement->next = node;
			node->last->next = newElement;
			node->last = newElement;*/
			Node* tmp = new Node;
			tmp->value = value2;
			tmp->next = node->next;
			tmp->last = node;
			node->next->last = tmp;
			node->next = tmp;

			return;
		}
		node = node->next;
	}
	cout << "There is not element = " << value;
}

void insert(Node* node, int value)
{
	Node* newNode = new Node;
	newNode->value = value;
	newNode->next = nullptr;
	newNode->last = node;

	while (node->next != nullptr)
	{
		node = node->next;
	}
	node->next = newNode;
}

void search(Node* node) {
	int value;
	cout << "Element to find: ";
	cin >> value;
	node = node->next;

	while (node != nullptr)
	{
		if (node->value == value)
		{
			cout << "There is element equal " << value << endl;
			return;
		}
		node = node->next;
	}
	cout << "There is not thet element" << endl;
}

void remove(Node*& node) {

	if (node->next == nullptr)
		return;

	int value;
	cout << "Value element to remove: ";
	cin >> value;

	Node* tmp = node;
	tmp = tmp->next;

	while (tmp->next->next != nullptr)
	{
		if (tmp->value == value)
		{
			delete tmp->next;		//wskaźnik
			tmp->next = nullptr;

		}
		tmp = tmp->next;
	}
	cout << "There is not element equal " << value;
}

void removeLast(Node*& node)
{
	if (node->next == nullptr)
	{
		return;
	}

	Node* preLast = node;
	while (preLast->next->next != nullptr)
	{
		preLast = preLast->next;
	}

	delete preLast->next;
	preLast->next = nullptr;
}

int main()
{
	Data data;
	Node* node = new Node;
	node->value = -999;
	node->next = nullptr;
	node->last = nullptr;

	for (int i = 1; i <= 10; i++)
	{
		insert(node, i * i);
	}

	print(node);
	//search(node);
	//removeLast(node);
	//print(node);
	cout << node->next << endl;

	insertMidleValue(node);
	print(node);
	cout << node->next << endl;


}