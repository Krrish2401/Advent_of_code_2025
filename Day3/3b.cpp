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

long long solve(vector<string> input){
    long long sum = 0;
    for(const string& s : input){
        string largest;
        long can_i = s.size()-12;
        for(char c : s){
            while(!largest.empty() && can_i > 0 && largest.back() < c){
                largest.pop_back();
                can_i--;
            }
            largest.push_back(c);
        }
        largest = largest.substr(0,12);
        sum+=stoll(largest);
    }
    return sum;
}

int main(){
    vector<string> input = readInput("3_sample.txt");
    cout << solve(input);
    return 0;
}