class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        map<char, pair<int, int>> m;
        // first and last appearance of the letter;
        for (int i = 0; i < s.size(); i++) {
            if (m.count(s[i])) {
                m[s[i]].second = i;
            } else {
                m[s[i]] = make_pair(i, i);
            }
        }

        pair<int, int> curr (m[s[0]].first, m[s[0]].second);
        for (int i = 1; i < s.size(); i++) {
            if (i > curr.second) {
                res.push_back(curr.second - curr.first + 1);
                curr = m[s[i]];
            } else {
                if (m[s[i]].second > curr.second) {
                    curr.second = m[s[i]].second;
                }
            }
        }

        res.push_back(curr.second - curr.first + 1);

        return res;
    }
};