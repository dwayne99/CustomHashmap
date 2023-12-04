
template<typename K, typename V>
class Node
{
public:
    K key;
    V value;
    Node<K, V>* next;

    Node(K key, V value);
};


template<typename K, typename V>
class LinkedList
{
    Node<K, V>* head;
    Node<K, V>* tail;

public:

    // constructors
    LinkedList();
    LinkedList(Node<K, V> node);

    // get the head node of the linked list
    const Node<K, V>* getHead() const;
    Node<K, V>* getHead();

    // get the tail node of the linked list
    const Node<K, V>* getTail() const;

    // insert to the back of the linked list
    void push_back(Node<K, V>* node);

    // erase a node from the list
    void erase(K key);

    // view the linkedlist
    void print() const;

};

