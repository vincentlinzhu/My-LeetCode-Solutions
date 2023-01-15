vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> m;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        map<int, int>::iterator it = m.find(nums[i]);
        if (it == m.end()) {
                m.insert(pair<int, int>(nums[i], 1));
        } else {
                it->second++;
        }
    }

    vector<vector<int>> freq(nums.size() + 1);
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        freq[it->second].push_back(it->first);
    }
    
    for (int i = nums.size(); i >= 0; i--) {
        if (res.size() >= k) {
            break;
        }
        if (freq.size() != 0) {
            for (auto& x : freq[i]) {
                res.push_back(x);
            }
        }
    }
    return res;
}