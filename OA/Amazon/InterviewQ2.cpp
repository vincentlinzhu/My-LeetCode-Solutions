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

int solve(vector<vector<int>> v) {
    int mostOnes = 0;
    int i = 0;
    int j = v[i].size() - 1;
    while (i < v.size()) {
        while (v[i][j] == 1) {
            mostOnes++;
            j--;
        }
        i++;
    }
    return mostOnes;
}

int main() {
    // most 1s ?
    vector<vector<int>> v {{0, 0, 0, 1, 1, 1}, {0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 1, 1}, {0, 0, 1, 1, 1, 1}};
    cout << solve(v) << endl;

    return 0;
}