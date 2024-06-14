#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>
#include <utility>
#include <sstream>
#include <set>
#include <iomanip>
#include <stack>
// #include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> matchPairs(vector<int>& l, vector<int>& r) {
    vector<pair<int, int>> res;
    map<int, int> leftFreq;
    for (int i = 0; i < l.size(); i++) {
        if (leftFreq.count(l[i]) == 0) {
            leftFreq[l[i]] = 1;
        } else {
            leftFreq[l[i]]++;
        }
    }

    pair<int, int> p;
    for (int i = 0; i < r.size(); i++) {
        if (leftFreq[r[i]] > 0) {
            leftFreq[r[i]]--;
            p.first = r[i];
            p.second = r[i];
            res.push_back(p);
        }
    }

    return res;
}

int main() {
    // int leftBin[], int rightBin[], each array contains shoe sizes in each bin
    // output available matching pairs you can make, duplicates matter
    vector<int> l {7, 1, 5, 3, 6, 4, 4, 4, 6, 6};
    vector<int> r {1, 1, 7, 4, 3, 3};
    for (auto p : matchPairs(l, r)) {
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }

    return 0;
}