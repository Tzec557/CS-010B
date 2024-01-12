#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool rCopy(string infile, string outfile);
bool rCopy(ifstream& in, ofstream& out);

int main(int argc, char* argv[]) {
    string inFileName;
    string oFileName;

    if (argc != 3) {
        cout << "Error" << endl;
        return 1;
    }

    inFileName = argv[1];
    oFileName = argv[2];
    rCopy(inFileName, oFileName);

    return 0;
}


bool rCopy( string inFileName,  string oFileName){
    ifstream inFS;
    inFS.open(inFileName);

    if(!inFS.is_open()){
        cout << "Error opening " << inFileName << endl; 
        cout << "Copy not completed" << endl; 
        return false;
    }

    ofstream outFS;
    outFS.open(oFileName);

    if(!outFS.is_open()){
        cout << "Error opening " << oFileName << endl; 
        cout << "Copy not completed" << endl; 
        return false;
    }

    bool a = rCopy(inFS, outFS);

    inFS.close();
    outFS.close();

    return a;
}

bool rCopy(ifstream& in, ofstream& out){
    char ch;
    if (in.get(ch)){
        if(rCopy(in, out)){
            out << ch; 
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
}