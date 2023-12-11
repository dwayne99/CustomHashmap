#include "hashmap.h"

template<
    typename K,
    typename V,
    typename Hash,
    typename KeyEqual
>
Hashmap<K, V, Hash, KeyEqual>::Hashmap(size_t size) 
: _size{size}, 
array{new LinkedList<K, V>[size]}
{
    // std::cout << "Hash created\n";
}

template<
    typename K,
    typename V,
    typename Hash,
    typename KeyEqual
>
void Hashmap<K, V, Hash, KeyEqual>::insert(K key, V value)
{

    size_t index = std::hash<K>()(key) % _size;

    if (array[index].head) // bucket exists. Insert if key is not present in it
    {
        if (!array[index].contains(key))
        {
            array[index].push_back(new Node<K, V>(key, value));
        }
        else
        {
            std::cout << "Insertion Failed: element with key = " << key << " exists.\n";
        }
    }
    else  // bucket is empty
    {
        array[index].push_back(new Node<K,V>(key, value));
    }

}
/**
 * Prints all the key value pairs in the hashmap
 * 
*/
template<
    typename K,
    typename V,
    typename Hash,
    typename KeyEqual
>
void Hashmap<K, V, Hash, KeyEqual>::print() const
{
    for (size_t i = 0; i < _size; ++i)
    {
        if(array[i].head)
        {
            array[i].print();
        }
    }
}

/**
 * calculates the size of the hashmap
*/
template<
    typename K,
    typename V,
    typename Hash,
    typename KeyEqual
>
size_t Hashmap<K, V, Hash, KeyEqual>::size() const
{
    size_t count = 0;
    for (size_t i = 0; i < _size; ++i)
    {
        if(array[i].head)
        {
            count += array[i].size();
        }
    }

    return count;
}

/**
 * returns true if hashmap is empty
*/
template<
    typename K,
    typename V,
    typename Hash,
    typename KeyEqual
>
bool Hashmap<K, V, Hash, KeyEqual>::empty() const
{
    for (size_t i = 0; i < _size; ++i)
    {
        if(array[i].head)
        {
            return false;
        }
    }
    return true;
}

/** * returns true if hashmap contains key
 * 
 * @param key that your searching for
 * 
 * @return true if key exists
*/
template<
    typename K,
    typename V,
    typename Hash,
    typename KeyEqual
>
V Hashmap<K, V, Hash, KeyEqual>::at(K key) const
{
    size_t index = std::hash<K>()(key) % _size;

    if (array[index].contains(key))
    {
        return array[index].getValue(key);
    } else {
        nullptr;
    }
}

/** * returns true if hashmap contains key
 * 
 * @param key that your searching for
 * 
 * @return true if key exists
*/
template<
    typename K,
    typename V,
    typename Hash,
    typename KeyEqual
>
bool Hashmap<K, V, Hash, KeyEqual>::contains(K key) const
{
    for(size_t i = 0; i < _size; ++i)
    {
        if (array[i].contains(key))
        {
            return true;
        }
    }

    return false;
}

/** * returns the value of the key
 * 
 * @param key that your searching for
 * 
 * @return value of the key
*/
template<
    typename K,
    typename V,
    typename Hash,
    typename KeyEqual
>
V Hashmap<K, V, Hash, KeyEqual>::operator[](K key) const 
{
    return  at(key);
}

template<
    typename K,
    typename V,
    typename Hash,
    typename KeyEqual
>
void Hashmap<K, V, Hash, KeyEqual>::erase(K key) 
{

    size_t index = std::hash<K>()(key) % _size;
    if (array[index].contains(key))
    {
        array[index].erase(key);
    }


}


/**
 * Hashmap destructor
*/
template<
    typename K,
    typename V,
    typename Hash,
    typename KeyEqual
>
Hashmap<K, V, Hash, KeyEqual>::~Hashmap()
{
    delete[] array;
}