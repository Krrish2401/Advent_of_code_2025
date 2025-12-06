#include <bits/stdc++.h>

using namespace std;

vector<string> readInput(const string& filename){
    vector<string> ops;
    ifstream file(filename);

    if(!file){
        cerr << "Could not open file " << filename << endl;
        return ops;
    }

    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string op;
        while(getline(ss, op, ',')){
            op.erase(0, op.find_first_not_of(" \t\n\r"));
            op.erase(op.find_last_not_of(" \t\n\r") + 1);
            if(!op.empty()){
                ops.push_back(op);
            }
        }
    }

    file.close();
    return ops;
}

inline int wrap(int x){
    x%= 100;
    if(x < 0) x+=100;
    return x;
}

int solve(const vector<string>& ops){
    int dial = 50;
    int c=0;
    for(string op : ops){
        int amount = stoi(op.substr(1));
        if(op[0]=='L') dial = wrap(dial - amount);
        if(op[0]=='R') dial = wrap(dial + amount);

        if(dial == 0) c++;
    }
    return c;
}

int main(){
    vector<string> input = readInput("1a_sample.txt");

    int result = solve(input);
    cout<<result;
    return 0;
}