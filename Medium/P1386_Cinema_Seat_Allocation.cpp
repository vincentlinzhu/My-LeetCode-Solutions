int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    int res = 0;
    unordered_map<int, vector<int>> m;
    for (auto pair : reservedSeats) {
        if (!m.count(pair[0])) {
            vector<int> v;
            v.push_back(pair[1]);
            m[pair[0]] = v;
        } else {
            m[pair[0]].push_back(pair[1]);
        }
    }
    res += (n - m.size()) * 2;

    bool c1 = false;
    bool c2 = false;
    for (auto x : m) {
        vector<int> v(11, 1);
        for (auto e : x.second) {
            v[e] = 0;
        }
        c1 = v[2] & v[3] & v[4] & v[5] & v[6] & v[7] & v[8] & v[9];
        c2 = (v[2] & v[3] & v[4] & v[5]) | (v[4] & v[5] & v[6] & v[7]) | (v[6] & v[7] & v[8] & v[9]);
        if (c1) {
            res += 2;
        } else if (c2) {
            res += 1;
        } 
    }

    return res;
}