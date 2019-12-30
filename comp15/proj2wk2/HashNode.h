#include <vector>
#include <string>

using namespace std;

#ifndef HASH_NODE_H_
#define HASH_NODE_H_

template<typename K, typename V>
class HashNode
{
public:
    V value;
    K key;
    vector<V> values;
    vector<int> line_values;

    HashNode(K key, V value){
        this->value = value;
        this->values = values;
        this->values.push_back(value);
        this->line_values = line_values;
        this->key = key;
    }

};

#endif
