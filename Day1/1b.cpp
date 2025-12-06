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

int hits(int start, char direction, int amount){
    int first_hit;
    if(direction == 'L'){
        first_hit = (100-start) % 100;
    }
    else{
        first_hit = start%100;
    }
    if(first_hit == 0) first_hit = 100;
    if(amount < first_hit) return 0;
    return 1 + (amount - first_hit)/100;
}

long long solve(const vector<string>& ops){
    int dial = 50;
    long long c=0;

    for(string op : ops){
        int amount = stoll(op.substr(1));
        int s = dial;
        int t0;

        if(op[0] == 'R'){
            t0 = (100-s) % 100;
        }
        else{
            t0 = s%100;
        }

        if(t0 == 0) t0 = 100;

        if(amount >= t0){
            c += 1 + ((amount-t0)/100);
        }

        if(op[0] == 'R') dial = wrap(dial + (int)(amount%100));
        else dial = wrap(dial - (int)(amount%100));
    }
    return c;
}

int main(){
    vector<string> input = readInput("1_sample.txt");

    int result = solve(input);
    cout<<result;
    return 0;
}