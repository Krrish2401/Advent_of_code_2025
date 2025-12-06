#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> readInput(const string& filename){
    vector<pair<long long, long long>> ranges;
    ifstream file(filename);
    string line;

    if(getline(file, line)){
        stringstream ss(line);
        string range;

        while(getline(ss, range, ',')){
            size_t pos = range.find('-');
            long long start = stoll(range.substr(0,pos));
            long long end = stoll(range.substr(pos+1));
            ranges.push_back({start,end});
        }
    }

    file.close();
    return ranges;
}

long long solve(vector<pair<long long, long long>> input){
    long long sum = 0;
    for(auto& p : input){
        for(long long i=p.first; i<p.second+1; i++){
            string s = to_string(i);
            if(s.size() % 2 == 0){
                long long half = s.size()/2;
                if(s.substr(0,half) == s.substr(half)) sum+=i;
            }
        }
    }
    return sum;
}

int main(){
    vector<pair<long long, long long>> input = readInput("2_sample.txt");
    cout<<solve(input);
    return 0;
}