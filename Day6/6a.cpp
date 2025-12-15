#include <bits/stdc++.h>
using namespace std;

// optional to create struct..was just feeling creative..hehe:)
struct InputData {
    vector<vector<long long>> nums;
    vector<char> ops;
};

InputData readWorksheet(const string& filename) {
    InputData data;
    ifstream file(filename);
    string line;
    vector<string> lines;

    while (getline(file, line)) {
        if (!line.empty())
            lines.push_back(line);
    }
    file.close();

    int n = lines.size();
    if (n < 2) return data;

    istringstream iss(lines.back());
    char op;
    while (iss >> op) data.ops.push_back(op);

    for (int i = 0; i < n - 1; i++) {
        istringstream iss(lines[i]);
        vector<long long> row;
        long long x;
        while (iss >> x) {
            row.push_back(x);
        }
        data.nums.push_back(move(row));
    }

    return data;
}

long long solve(const InputData& data) {
    int rows = data.nums.size();
    int cols = data.ops.size();

    long long grandTotal = 0;

    for (int c = 0; c < cols; c++) {
        int val = (data.ops[c] == '*') ? 1 : 0;

        for (int r = 0; r < rows; r++) {
            if (data.ops[c] == '*')
                val *= data.nums[r][c];
            else
                val += data.nums[r][c];
        }

        grandTotal += (long long)val;
    }

    return grandTotal;
}

int main() {
    InputData data = readWorksheet("6_sample.txt");
    cout << solve(data);
    return 0;
}
