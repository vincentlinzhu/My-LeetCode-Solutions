bool isPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;
    while (l < r) {
        while (!isalnum(s[l]) && l < r) {
            l++;
        }
        while (!isalnum(s[r]) && l < r) {
            r--;
        }
        if (tolower(s[l]) != tolower(s[r])) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void dfs(string s, vector<string>& v, vector<vector<string>>& res) {
    // int partition = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isPalindrome(s.substr(0,  i + 1))) {
            vector<string> y = v;
            v.push_back(s.substr(0, i + 1));
            if (i == s.size() - 1) {
                res.push_back(v);
                return;
            }
            dfs(s.substr(i + 1), v, res);
            v = y;
        } else {
            if (i == s.size() - 1) {
                return;
            }
        }
    }
    return;
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> v;
    dfs(s, v, res);
    return res;
}