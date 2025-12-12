#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> readRanges(const string& filename){
    vector<pair<long long, long long>> ranges;
    ifstream file(filename);
    string line;

    while(getline(file, line)){
        if (line.empty()) break;

        size_t dashpos = line.find('-');
        if (dashpos != string::npos){
            long long start = stoll(line.substr(0, dashpos));
            long long end = stoll(line.substr(dashpos+1));
            ranges.push_back({start, end});
        }
    }

    file.close();
    return ranges;
}

vector<long long> readID(const string& filename){
    vector<long long> ids;
    ifstream file(filename);
    string line;
    bool there_yet = false;

    while(getline(file, line)){
        if (line.empty()){
            there_yet = true;
            continue;
        }

        if(there_yet){
            ids.push_back(stoll(line));
        }
    }

    file.close();
    return ids;
}

long long solve(vector<pair<long long, long long>> ranges, vector<long long> ids){
    long long c = 0;
    
    for(long long id : ids){
        for(auto &r : ranges){
            if(id >= r.first && id <= r.second){
                c++;
                break;
            }
        }
    }
    return c;
}

int main(){
    vector<pair<long long, long long>> ranges = readRanges("5_sample.txt");
    vector<long long> ids = readID("5_sample.txt");
    cout<<solve(ranges, ids);
    return 0;
}