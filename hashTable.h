#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>

using namespace std;

class hashTable
{
    private:
        int size;
        struct HashNode
        {
            int fileNum;
            HashNode *next;
        };
        HashNode *table[];

    int hashFunction(string value);
    public:
        hashTable(int size);
        void insertItem(string item,int fileNum);
        void deleteItem(int key);

};

#endif