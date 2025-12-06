#include <bits/stdc++.h>
using namespace std;

vector<string> readInput(const string& filename){
    vector<string> lines;
    ifstream file(filename);
    string line;

    while(getline(file, line)){
        if(!line.empty()){
            lines.push_back(line);
        }
    }

    file.close();
    return lines;
}

long long solve(vector<string>& input){
    long long sum=0;
    for(const string& s : input){
        int maxy = -1;
        int before = -1;
        for(char c : s){
            int n = c - '0';
            if(before != -1){
                maxy = max(maxy, before*10+n);
            }
            before = max(before, n);
        }
        sum+=maxy;
    }

    return sum;
}

int main(){
    vector<string> input = readInput("3_sample.txt");
    cout<<solve(input);
    return 0;
}