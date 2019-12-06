#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }
    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

void printQueue(queue<string> q){
    for(int i = 0; i < q.size(); i++){
        string temp = q.front();
        cout<<temp;
        q.push(temp);
        q.pop();
    }
    cout<<endl;
}

void getSequences(vector<string> &files, int n, string dir){
    for(int fileInd = 0; fileInd < files.size(); fileInd++){
        string fileLoc = ("./" + dir + "/" + files[fileInd]);
        ifstream inFile(fileLoc.c_str(), fstream::in);
        //inFile.open(fileLoc, ios_base::openmode mode = ios_base::in);
        //inFile.open(fileLoc, ifstream::in);
        queue<string> sequence;
        if (inFile.fail()) {
            cout << "File doesn't exist" << endl;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (inFile.peek() != EOF) {
                    string temp;
                    inFile >> temp;
                    sequence.push(temp);
                }
            }
            printQueue(sequence);
            while (inFile.peek() != EOF) {
                sequence.pop();
                string temp;
                inFile >> temp;
                sequence.push(temp);
                printQueue(sequence);
                }
        }
        inFile.close();
    }
}

int main()
{
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();
    int n = 6;

    getdir(dir,files);
    getSequences(files,n,dir);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }
    return 0;
}

