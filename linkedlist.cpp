#include "linkedlist.h"
#include <utility>

/**
 * Node: Constructor
*/
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

/**
 * LinkedList: Default constructor
*/
template<typename K, typename V>
LinkedList<K, V>::LinkedList() : head{nullptr}, tail{nullptr} {}

/**
 * LinkedList: one element constructor
*/
template<typename K, typename V>
LinkedList<K, V>::LinkedList(Node<K, V>* node) : head{node}, tail{node} {}

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
 * LinkedList: Copy assignment
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

/**
* LinkedList: Move constructor
*/
template<typename K, typename V>
LinkedList<K, V>::LinkedList(LinkedList<K, V>&& other_ll) 
: head{std::exchange(other_ll.head, nullptr)}, 
tail{std::exchange(other_ll.tail, nullptr)} 
{
}

/**
* LinkedList: Move assingment
*/
template<typename K, typename V>
LinkedList<K, V>& LinkedList<K, V>::operator=(LinkedList<K, V>&& other_ll) 
{
    delete head;
    head = nullptr;
    tail = nullptr;
    if (this != &other_ll)
    {
        this->head = std::exchange(other_ll.head, nullptr);
        this->tail = std::exchange(other_ll.tail, nullptr);
        return *this;
    }
    else { return *this; }
}

/**
* LinkedList: Check if a node with Key exists
*
* @param Key to check for among all the nodes
* @return true if Key exists else false
*/
template<typename K, typename V>
bool LinkedList<K, V>::contains(K key) 
{
    Node<K, V>* ptr = head;

    while (ptr)
    {
        if (ptr->key == key) { return true; }
        ptr = ptr->next;
    }

    return false;
}


/**
 * Returns a const pointer to the head/start of the linked list
 * 
 * @return head : const pointer to the start of the list
*/
template<typename K, typename V>
const Node<K, V>* LinkedList<K, V>::getHead() const
{
    return head;
}

/**
 * Returns a pointer to the head/start of the linked list
 * 
 * @return head : pointer to the start of the list
*/
template<typename K, typename V>
Node<K, V>* LinkedList<K, V>::getHead() 
{
    return head;
}

/**
 * Returns a pointer to the tail/end of the list
 * 
 * @return head : pointer to the end of the list
*/
template<typename K, typename V>
const Node<K, V>* LinkedList<K, V>::getTail() const
{
    return tail;
}


/**
 * Inserts a node to the back of the linked list
 * 
 * @param node : the node to be inserted
*/
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

/**
 * Deletes a node from the linked list with a particular key
 * 
 * @param key of the node to delete 
*/
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

/**
 * Prints the contents (key, value) of a node
*/
template<typename K, typename V>
void Node<K, V>::print() const
{
    std::cout << "(" << this->key << ", " << this->value << ")\n";
}

/**
 * Prints the linked list
*/
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

/**
 * returns the value of the key within the linked list
*/
template<typename K, typename V>
V LinkedList<K, V>::getValue(K key) const
{
    Node<K, V>* ptr = head;

    while (ptr)
    {
        if (ptr->key == key) { return ptr->value; } 
        ptr = ptr->next;
    }

    return -1;
}


/**
 * returns the size of the linked list
*/
template<typename K, typename V>
size_t LinkedList<K, V>::size() const
{
    Node<K, V>* ptr = head;
    size_t count = 0;

    while (ptr)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}

/**
 * Destructor: frees all the resources allocated by the linkedlist
*/
template <typename K, typename V>
LinkedList<K, V>::~LinkedList()
{
    delete head; // cascading destruction of all nodes pointed by head

    head = nullptr;
    tail = nullptr;
        
    // std::cout << "LinkedList destroyed!\n";
}

