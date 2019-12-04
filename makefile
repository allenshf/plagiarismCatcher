final: plagiarismCatcher.o
	g++ -otest plagiarismCatcher.o
plagiarismCatcher.o: plagiarismCatcher.cpp
	g++ -c plagiarismCatcher.cpp
