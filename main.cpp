#include <iostream>
#include <random>
#include "HashTable.h"


using namespace std;

int main() {

    HashTable<string> * ht = new HashTable<string>(128);
    int option;

    cout << "================== STARTING THE PROGRAM ================== " << endl;

    do {
        cout << "Choose your options:" << endl;
        cout << "1. add / update position" << endl;
        cout << "2. get value from key" << endl;
        cout << "3. remove position" << endl;
        cout << "0. exit" << endl;

        cin >> option;
        int key;
        string value;

        switch(option) {

            case 1:
                cout << "Enter a number:" << endl;
                cin >> key;
                cout << "Enter a value:" << endl;
                cin >> value;
                ht->put(key, value);
                break;

            case 2:
                cout << "Enter a number:" << endl;
                cin >> key;
                cout << "The key's value is " << ht->get(key) << endl;
                break;

            case 3:
                cout << "Enter a position:" << endl;
                cin >> key;
                ht->remove(key);
                cout << "The value was removed" << endl;
                break;

            case 0:
                exit(0);
        }



    } while(option != 0);

    return 0;
}