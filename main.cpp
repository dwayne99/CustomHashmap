#include <iostream>

#include "hashmap.cpp"



int main() 
{


    Hashmap<std::string, float> hm; 

    hm.insert("dwayne", 102.3);
    hm.insert("abis", 9.3);
    hm.print();


    std::cout << "-----\n";
    hm.erase("abis");
    hm.print();
    std::cout << "-----\n";


    hm.insert("lester", 3.33);
    hm.insert("vernon", 2.3);
    hm.insert("celeste", 33.23);
    hm.print();




    // LinkedList<int, float> ll(new Node<int,float>(0,0.23));
    // ll.push_back(new Node<int, float>(1,2.23));
    // ll.push_back(new Node<int, float>(10,20));
    // ll.push_back(new Node<int, float>(100,20.4));
    // ll.print();

    // std::cout << "-----\n";
    // ll.erase(1);
    // ll.print();

    // LinkedList<int, float> ll2(new Node<int,float>(2,0.3));
    // ll2.push_back(new Node<int, float>(2,2));
    // ll2.push_back(new Node<int, float>(2,20.34));
    // ll2.push_back(new Node<int, float>(2,200.3));

    // LinkedList<int, float> ll3{new Node<int, float>(2,3.34)};
    // ll3 = std::move(ll2);
    
    // ll.print();
    // std::cout << "-----\n";
    // ll2.print();
    // std::cout << "-----\n";
    // ll3.print();


    return 0;
}
