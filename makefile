final: plagiarismCatcher.o hashTable.o
	g++ -otest plagiarismCatcher.o hashTable.o
plagiarismCatcher.o: plagiarismCatcher.cpp hashTable.h
	g++ -c plagiarismCatcher.cpp
hashTable.o: hashTable.cpp hashTable.h
    g++ -c hashTable.cpp
