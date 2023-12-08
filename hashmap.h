#include "linkedlist.cpp"
#include <functional>

template<
    typename K, 
    typename V,
    typename Hash = std::hash<K>,
    typename KeyEqual = std::equal_to<K>
>
class Hashmap
{

private:
    size_t _size;
    LinkedList<K, V>* array;

public:
    Hashmap(size_t size = 10);
    void insert(K key, V value); // to insert key-value into the hashmap
    void erase(K key); // to remove key-value from hashmap

    bool empty() const; // returns True if hashmap is empty
    size_t size() const; // return number of key-value pairs / size of the hashmap

    // for lookup
    V at(K key) const; 
    V operator[](size_t index);
    bool contains(K key) const; // checks if element with key exists in the hashmap, if so return True

    // print
    void print() const;

    ~Hashmap(); // destructor


};
