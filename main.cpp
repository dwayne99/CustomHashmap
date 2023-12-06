#include <iostream>

// #include "hashmap.h"

#include "linkedlist.cpp"


int main() 
{

    LinkedList<int, int> ll(new Node<int,int>(0,0));
    ll.push_back(new Node<int, int>(1,2));
    ll.push_back(new Node<int, int>(10,20));
    ll.push_back(new Node<int, int>(100,200));
    // ll.print();

    LinkedList<int, int> ll2(new Node<int,int>(2,0));
    ll2.push_back(new Node<int, int>(2,2));
    ll2.push_back(new Node<int, int>(2,20));
    ll2.push_back(new Node<int, int>(2,200));

    ll2 = ll;
    ll.tail->key = 1001;
    ll2.tail->key = 1000;
    
    ll.print();
    std::cout << "-----\n";
    ll2.print();


    return 0;
}
