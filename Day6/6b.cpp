#include <bits/stdc++.h>
using namespace std;

struct InputData {
    vector<long long> nums;
    char op;
};

vector<InputData> readInput(const string& filename) {
    ifstream file(filename);
    vector<string> lines;
    string line;

    while (getline(file, line)) {
        if (!line.empty())
            lines.push_back(line);
    }
    file.close();

    int rows = lines.size();
    int cols = lines[0].size();

    vector<InputData> data;

    int c = 0;
    while (c < cols) {
        bool khali_hai = true;
        for (int r = 0; r < rows; r++) {
            if (c < lines[r].size() && lines[r][c] != ' ') {
                khali_hai = false;
                break;
            }
        }
        if (khali_hai) {
            c++;
            continue;
        }
        int start = c;
        while (c < cols) {
            bool alag_hai = true;
            for (int r = 0; r < rows; r++) {
                if (c < lines[r].size() && lines[r][c] != ' ') {
                    alag_hai = false;
                    break;
                }
            }
            if (alag_hai) break;
            c++;
        }
        int end = c - 1;

        InputData d;

        for (int x = start; x <= end; x++) {
            char ch = lines[rows - 1][x];
            if (ch == '+' || ch == '*') {
                d.op = ch;
                break;
            }
        }

        for (int x = end; x >= start; x--) {
            long long value = 0;
            bool kuch_hai = false;

            for (int r = 0; r < rows - 1; r++) {
                char ch = lines[r][x];
                if (isdigit(ch)) {
                    value = value * 10 + (ch - '0');
                    kuch_hai = true;
                }
            }

            if (kuch_hai)
                d.nums.push_back(value);
        }

        data.push_back(d);
    }

    return data;
}

long long solvePart2(const vector<InputData>& data) {
    long long total = 0;

    for (const auto& p : data) {
        long long val = (p.op == '*') ? 1 : 0;
        for (long long x : p.nums) {
            if (p.op == '*') val *= x;
            else val += x;
        }
        total += val;
    }

    return total;
}

int main() {
    auto problems = readInput("6_sample.txt");
    cout << solvePart2(problems);
    return 0;
}
