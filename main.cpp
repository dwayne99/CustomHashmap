#include <iostream>

// #include "hashmap.h"

#include "linkedlist.cpp"


int main() 
{

    // LinkedList<int, int> ll(new Node<int,int>(0,0));
    // ll.push_back(new Node<int, int>(1,2));
    // ll.push_back(new Node<int, int>(10,20));
    // ll.push_back(new Node<int, int>(100,200));
    // ll.print();

    Node<int, int> n1{1,2};
    Node<int, int> n2{10,20};


    n1.print();
    n2.print();

    Node<int, int> n3{std::move(n1)};

    n1.print();
    n2.print();
    n3.print();

    n3 = std::move(n2);
    n1.print();
    n2.print();
    n3.print();

    return 0;
}
