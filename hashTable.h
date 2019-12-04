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

        int hashFunction(string value);
    public:
        hashTable(int size);
        void insertItem(string item);
        void deleteItem(string item);

};