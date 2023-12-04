#include "linkedlist.h"

template<typename K, typename V>
Node<K, V>::Node(K key, V value) : key(key), value(value), next( nullptr ) {}

template<typename K, typename V>
LinkedList<K, V>::LinkedList() : head(nullptr), tail(nullptr) {}

template<typename K, typename V>
LinkedList<K, V>::LinkedList(Node<K, V> node) : head(&node), tail(&node) {}

template<typename K, typename V>
const Node<K, V>* LinkedList<K, V>::getHead() const
{
    return head;
}

template<typename K, typename V>
const Node<K, V>* LinkedList<K, V>::getTail() const
{
    return tail;
}

template<typename K, typename V>
Node<K, V>* LinkedList<K, V>::getHead() 
{
    return head;
}

template<typename K, typename V>
void LinkedList<K, V>::push_back(Node<K, V>* node)
{

    if (head != nullptr) 
    {
        tail->next = node;
        tail = node;
    } 
    else 
    {
        head = node;
        tail = node;
    }

}

template <typename K, typename V>
void LinkedList<K, V>::erase(K key) 
{
    // either one or no node
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else if (head->key == key) 
    {
        Node<K, V>* ptr = head;
        head = head->next;
        delete ptr;
    }
    else
    {
        Node<K, V>* p1 = head;
        Node<K, V>* p2 = head->next;

        while (p2 && p2->key != key)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        p1->next = p2->next;
        delete p2;

        if (p1->next == nullptr)
        {
            tail = p1;
        }
    }
}

template<typename K, typename V>
void LinkedList<K, V>::print() const
{
    Node<K, V>* ptr = head;

    while (ptr)
    {
        std::cout << "(" << ptr->key << ", " << ptr->value << ")\n";
        ptr = ptr->next;
    }
}