void dfs(string digits, string& s, vector<string>& res, unordered_map<char, vector<string>> m) {
    string temp = s;
    if (digits.size() == 0) {
        return;
    }
    for (auto x : m[digits[0]]) {
        temp += x;
        dfs(digits.substr(1), temp, res, m);
        if (digits.size() == 1) {
            res.push_back(temp);
        }
        temp = s;
    }

    return;
}
vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
        return {};
    }
    // create a map of numbers to digits
    vector<string> res;
    unordered_map<char, vector<string>> m = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}}
    };
    string s = "";
    dfs(digits, s, res, m);
    return res;
}