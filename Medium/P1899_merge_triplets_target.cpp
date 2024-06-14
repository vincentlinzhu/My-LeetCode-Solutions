bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<vector<int>> v;
    vector<bool> res {false, false, false};
    bool greater = false;

    for (int i = 0; i < triplets.size(); i++) {
        greater = true;
        for (int j = 0; j < 3; j++) {
            if (triplets[i][j] > target[j]) {
                greater = false;
                break;
            }
        }
        if (greater) v.push_back(triplets[i]);
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i][j] == target[j]) {
                res[j] = true;
            }
        }
    }

    return (res[0] && res[1] && res[2]);
}