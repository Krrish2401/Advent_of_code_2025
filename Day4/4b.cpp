#include <bits/stdc++.h>
using namespace std;

vector<string> readInput(const string& filename) {
    vector<string> grid;
    ifstream file(filename);
    string line;
    
    while (getline(file, line)) {
        if (!line.empty()) {
            grid.push_back(line);
        }
    }
    
    file.close();
    return grid;
}

long long solve(vector<string> input){
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    long long removed = 0;
    while(true){
        vector<pair<int, int>> bye_guys;
        long long c = 0;
        for(int i=0; i<input.size(); i++){
            for(int j=0; j<input[0].size(); j++){
                if(input[i][j]!='@') continue;
                int rolls = 0;
                for(int x=0; x<8; x++){
                    int gx = i+dx[x];
                    int gy = j+dy[x];
                    if(gx < 0 || gy < 0 || gx >= input.size() || gy >= input[0].size()) continue;
                    if(input[gx][gy]=='@') rolls++;
                }
                if(rolls < 4) bye_guys.emplace_back(i,j);
            }
        }
        if(bye_guys.empty()) break;
        removed += bye_guys.size();
        for(auto i : bye_guys){
            input[i.first][i.second] = '.';
        }
    }
    return removed;
}

int main(){
    vector<string> input = readInput("4_sample.txt");
    cout<< solve(input);
    return 0;
}