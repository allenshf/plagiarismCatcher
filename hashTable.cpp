#include "hashTable.h"

using namespace std;

hashTable::hashTable(int size) {
    this->size = size;
    table = new *HashNode[size];
}

int hashTable::hashFunction(string value) {
    int val = 0;
    int powerOf27 = 1;
    for(int i = 0; i < value.size(); i++){
        val += value.at(i) * powerOf27;
        powerOf27 = powerOf27 * 27;
    }
    int val = val % size;
    return abs(val);
}

void hashTable::insertItem(string item, int fileNum) {
    int key = hashFunction(item);
    HashNode* temp = table[key];
    if(temp == NULL){
        *temp = new (HashNode);
        temp->fileNum = fileNum;
        temp->next = NULL;
        table[key] = temp;
        return;
    }
    while(temp != NULL){
        temp = temp->next;
    }
    *temp = new (HashNode);
    temp->fileNum = fileNum;
    temp->next = NULL;
    table[key] = temp;
}

void hashTable::deleteItem(int key) {
    if(table[key] == NULL)
        return;
    HashNode *temp = table[key];
    table[key] = temp->next;
    delete temp;
}n