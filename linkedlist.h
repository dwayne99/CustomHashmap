
template<typename K, typename V>
class Node
{
public:
    K key;
    V value;
    Node<K, V>* next;

    Node(K key, V value);
    Node(Node<K, V>& other_node); // copy constructor
    Node<K, V>& operator=(Node<K, V>& other_node); // copy assignment
    Node(Node<K, V>&& other_node);
    Node<K, V>& operator=(Node<K, V>&& other_node);
    void print() const;
    ~Node();
};


template<typename K, typename V>
class LinkedList
{

public:
    Node<K, V>* head;
    Node<K, V>* tail;

    // constructors
    LinkedList();
    LinkedList(Node<K, V>* node);

    //copy constructor and copy assignment
    LinkedList(LinkedList<K, V>& other_ll);
    LinkedList<K, V>& operator=(LinkedList<K, V>& other_ll);


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

    //destructor
    ~LinkedList();

};

