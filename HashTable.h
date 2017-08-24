//
// Created by Leonardo Ribeiro on 23/08/17.
//

#ifndef TRABALHO_1_HASHTABLE_H
#define TRABALHO_1_HASHTABLE_H


#include <cstdlib>
#include "Node.h"

template<typename T>
class HashTable {

private:
    int TABLE_SIZE;
    int TABLE_POSITION;
    Node<T>* data[];

public:

    HashTable(int table_size) {
        this->TABLE_SIZE = table_size;
        this->TABLE_POSITION = 0;
        for(int i = 0; i < table_size; i++) {
            this->data[i] = nullptr;
        }
    }

    HashTable(int table_size, Node<T>* data) {
        this->TABLE_SIZE = table_size;
        this->TABLE_POSITION = 0;
        for(int i = 0; i < table_size; i++) {
            this->data[i] = nullptr;
        }
        this->data[0] = data;
    }

};


#endif //TRABALHO_1_HASHTABLE_H
