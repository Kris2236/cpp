/*  2. Zastosowania listy do implementacji tablicy rzadkiej. Proszę napisać trzy funkcje:
        - void init(node *&tab) – inicjalizującą tablicę,
        - int value(node *tab, int n) – zwracającą wartość elementu o indeksie n,
        - void set(node *&tab, int n, int value) – postawiającą wartość value pod indeks n.           */

#include <iostream>
using namespace std;

struct node {
    int value;
    int index;
    node* next = nullptr;
};

void init(node*& tab) {
    tab = nullptr;
}

int value(node* tab, int n) {

    while (tab) {           //wskaźnik na element tablicy (lista)
        if (tab->index == n) {
            n = tab->value;
            return n;
        }
        tab = tab->next;
    }

    cout << "Brak elementu o danym indeksie\n";
    return false;
}

void set(node*& tab, int n, int value) {
    
    node* tmp = tab;
    while (tmp)
    {
        if (tmp->index == n)
        {
            tmp->value = value;
            return;
        }
        tmp = tmp->next;
    }

    cout << "Brak elementu o podanym indeksie\n";
    node* newElement = new node;
    newElement->value = value;
    newElement->next = nullptr;
    newElement->index = n;
    tmp->next = newElement;
    tab = tmp;
}

int main()
{
    node* tab = new node;
    
}
