#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>

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
    for(string f:files) {
        string fileLoc("./" + dir + "/" + f);
        ifstream infile(fileLoc, ios::in);
        queue<string> sequence;
        if (infile.fail()) {
            cout << "File doesn't exist" << endl;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (infile.peek() != EOF) {
                    string temp;
                    infile >> temp;
                    sequence.push(temp);
                }
            }
            printQueue(sequence);
            while (infile.peek() != EOF) {
                sequence.pop();
                string temp;
                infile >> temp;
                sequence.push(temp);
                printQueue(sequence);
                }
        }
        infile.close();
    }
}


int main()
{
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();
    int n = 50;

    getdir(dir,files);
    getSequences(files,n,dir);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }
    return 0;
}

