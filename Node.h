//
// Created by Leonardo Ribeiro on 23/08/17.
//

#ifndef TRABALHO_1_NODE_H
#define TRABALHO_1_NODE_H

template <typename T>
class Node {


private:
    int key;
    T * value;
    Node<T> * nextNode;

public:

    Node(int key, T* value) {
        this->key = key;
        this->value = value;
    }

    int getKey() {
        return this->key;
    }

    T getValue(){
        return this->value;
    }

    void setKey(int key) {
        this->key = key;
    }

    void setValue(T* value){
        this->value = value;
    }

    Node<T> * next() {
        return this->nextNode;
    }

    void setNext(Node<T> * data) {
        this->nextNode = data;
    }

};


#endif //TRABALHO_1_NODE_H
