private:    
unordered_map<string, vector<pair<int, string>>> m;

public:
TimeMap() {

}

void set(string key, string value, int timestamp) {
    if (m.count(key) == 0) {
        vector<pair<int, string>> v;
        v.push_back(pair<int, string>(timestamp, value));
        m[key] = v;
    } else {
        m[key].push_back(pair<int, string>(timestamp, value));
    }
}

string get(string key, int timestamp) {
    string res = "";
    if (m.count(key)) {
        //binary search for the timestamp
        int l = 0; 
        int r = m[key].size() - 1;
        while (l <= r) {
            int mid = (r - l)/2 + l;
            if (m[key][mid].first <= timestamp) {
                if (m[key][mid].first == timestamp) {
                    res = m[key][mid].second;
                    return res;
                }
                res = m[key][mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return res;
}