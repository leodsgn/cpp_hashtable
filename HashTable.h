//
// Created by Leonardo Ribeiro on 23/08/17.
//

#ifndef TRABALHO_1_HASHTABLE_H
#define TRABALHO_1_HASHTABLE_H


#include <cstdlib>
#include <cmath>
#include "Node.h"

template<typename T>
class HashTable {

private:
    int TABLE_SIZE;
    int TABLE_POSITION;
    Node<T> **data;

public:

    /**
     * Hashtable constructor
     * @param table_size
     */
    HashTable(int table_size) {
        this->TABLE_SIZE = table_size;
        this->TABLE_POSITION = 0;
        this->data = new Node<T>*[TABLE_SIZE];
    }

    /**
     * Hashtable constructor
     * @param table_size
     * @param data
     */
    HashTable(int table_size, Node<T>* data) {
        this->TABLE_SIZE = table_size;
        this->TABLE_POSITION = 0;
        this->data = new Node<T>*[TABLE_SIZE];
    }

    /**
     * get value from a hash table
     * @param key
     * @return
     */
    Node<T> * get(int key) {
        int hash = hashFunction(key);

        if(data[hash] == nullptr ) {
            return nullptr;
        }
        else {
            Node<T> * entry = data[hash];

            while(entry != nullptr && entry->getKey() != key)
                entry = entry->next();
            if(entry == nullptr)
                return nullptr;
            else
                return entry->getValue();
        }
    }

    /**
     * update and instert values in the hashtable
     * @param key
     * @param value
     */
    void put(int key, T * value) {
        int hash = hashFunction(key);

        if(data[hash] == nullptr)
            data[hash] = new Node<T>(key, value);
        else {
            Node<T> * entry = data[hash];

            while(entry->next() != nullptr)
                entry = entry->next();
            if(entry->getKey() == key)
                entry->setValue(value);
            else
                entry->setNext(new Node<T>(key, value));
        }
    }

    void remove(int key) {
        int hash = hashFunction(key);

        if(data[hash] != nullptr){
            Node<T> * prevEntry = nullptr;
            Node<T> * entry = data[hash];

            while(entry->next() != nullptr && entry->getKey() != key) {
                prevEntry = entry;
                entry = entry->next();
            }

            if(entry->getKey() == key) {
                if(prevEntry == nullptr) {
                    Node<T> * nextEntry = entry->next();
                    delete entry;
                    data[hash] = nextEntry;
                }
                else {
                    Node<T> * next = entry->next();
                    delete entry;
                    prevEntry->setNext(next);
                }
            }
        }

    }

    /**
     * HashTable destructor
     */
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (data[i] != nullptr) {
                Node<T> *prevEntry = nullptr;
                Node<T> *entry = data[i];
                while (entry != nullptr) {
                    prevEntry = entry;
                    entry = entry->next();
                    delete prevEntry;
                }
            }
        delete[] data;
    }

    /**
     *  return hashtable location
     * @param key
     * @return
     */
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

};


#endif //TRABALHO_1_HASHTABLE_H
