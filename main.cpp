#include <iostream>

// #include "hashmap.h"

#include "linkedlist.cpp"


int main() 
{

    LinkedList<int, int> ll;
    Node<int, int>* n = new Node<int, int>(1,2);
    ll.push_back(n);

    Node<int, int>* n2 = new Node<int, int>(10,20);
    ll.push_back(n2);

    Node<int, int>* n3 = new Node<int, int>(109,201);
    ll.push_back(n3);
    ll.print();


    ll.erase(109);
    ll.print();
    // Node<int, int>* n = ll.getHead();


    return 0;
}
