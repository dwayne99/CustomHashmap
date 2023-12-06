#include "linkedlist.h"

template<typename K, typename V>
Node<K, V>::Node(K key, V value) : key{key}, value{value}, next{nullptr} {}

/**
 * Node: Copy constructor
*/
template<typename K, typename V>
Node<K, V>::Node(Node<K, V>& other_node) : key{other_node.key}, value{other_node.value}, next{other_node.next} {}

/**
 * Node: Copy assignment operator
*/
template<typename K, typename V>
Node<K,V>& Node<K, V>::operator=(Node<K, V>& other_node)
{
    if (this == &other_node) {return *this;}
    else
    {
        this->key = other_node.key;
        this->value = other_node.value;
        this->next = other_node.next;
        return *this;
    }
}

/**
 * Node: Move constructor
*/
template<typename K, typename V>
Node<K, V>::Node(Node<K, V>&& other_node) 
: key{std::exchange(other_node.key, 0)}, 
value{std::exchange(other_node.value, 0)}, 
next{std::exchange(other_node.next, nullptr)}
{}

/**
 * Node: Move assignment operator
*/
template<typename K, typename V>
Node<K, V>& Node<K, V>::operator=(Node<K, V>&& other_node) 
{
    if (this == &other_node) {return *this;}
    else
    {
        this->key = std::exchange(other_node.key, 0);
        this->value = std::exchange(other_node.value, 0);
        this->next = std::exchange(other_node.next, nullptr);
        return *this;
    }
}


/**
 * Node: Destructor
*/
template<typename K, typename V>
Node<K, V>::~Node()
{
    delete next;
    // std::cout << "Node destroyed!\n";
}

template<typename K, typename V>
LinkedList<K, V>::LinkedList() : head{nullptr}, tail{nullptr} {}

/**
 * LinkedList: Copy constructor
*/
template<typename K, typename V>
LinkedList<K, V>::LinkedList(LinkedList<K, V>& other_ll) 
{
    if (other_ll.head) // at least one node in the list
    {
        Node<K, V>* ptr = new Node<K, V>{*(other_ll.head)};
        head = ptr;
        tail = ptr;
        ptr = ptr->next;
        while(ptr)
        {
            Node<K, V>* node = new Node<K, V>{*ptr};
            tail->next = node;
            tail = node;
            ptr = ptr->next;
        }

    }
    else 
    {
        head = nullptr;
        tail = nullptr;
    }
}

/**
 * LinkedList: Copy constructor
*/
template<typename K, typename V>
LinkedList<K, V>& LinkedList<K, V>::operator=(LinkedList<K, V>& other_ll) 
{
    if (this != &other_ll)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        if (other_ll.head) // at least one node in the list
        {
            Node<K, V>* ptr = new Node<K, V>{*(other_ll.head)};
            head = ptr;
            tail = ptr;
            ptr = ptr->next;
            while(ptr)
            {
                Node<K, V>* node = new Node<K, V>{*ptr};
                tail->next = node;
                tail = node;
                ptr = ptr->next;
            }

        }
        else 
        {
            head = nullptr;
            tail = nullptr;
        }
        return *this;
    }
    else { return *this;}
}



template<typename K, typename V>
LinkedList<K, V>::LinkedList(Node<K, V>* node) : head{node}, tail{node} {}

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
void Node<K, V>::print() const
{
    std::cout << "(" << this->key << ", " << this->value << ")\n";
}

template<typename K, typename V>
void LinkedList<K, V>::print() const
{
    Node<K, V>* ptr = head;

    while (ptr)
    {
        ptr->print();
        ptr = ptr->next;
    }
}

template <typename K, typename V>
LinkedList<K, V>::~LinkedList()
{
    delete head; // cascading destruction of all nodes pointed by head

    head = nullptr;
    tail = nullptr;
        
    std::cout << "LinkedList destroyed!\n";
}

