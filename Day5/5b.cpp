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

long long solve(vector<pair<long long,long long>> ranges){
    sort(ranges.begin(), ranges.end());

    long long c = 0;

    long long L = ranges[0].first;
    long long R = ranges[0].second;

    for (int i = 1; i < ranges.size(); i++){
        auto [l, r] = ranges[i];

        if (l > R + 1){
            c += (R - L + 1);
            L = l;
            R = r;
        }
        else{
            R = max(R, r);
        }
    }

    c+=(R-L+1);
    return c;
}

int main(){
    vector<pair<long long, long long>> ranges = readRanges("5_sample.txt");
    cout<<solve(ranges);
    return 0;
}