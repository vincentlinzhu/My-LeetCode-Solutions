void helper(int o, int c, int n, stack<char> s, vector<string>& v) {
    if ((o == n) && (c == n)) {
        string comb;
        comb.resize(s.size());
        auto it = comb.rbegin(); // use reverse iteration over the string
        while (!s.empty()) {
            *it = s.top();
            s.pop();
            ++it;
        }
        v.push_back(comb);
    }

    if (c < o) {
        s.push(')');
        helper(o, c + 1, n, s, v);
        s.pop();
    }
    
    if (o < n) {
        s.push('(');
        helper(o + 1, c, n, s, v);
        s.pop();
    }
}
vector<string> generateParenthesis(int n) {
    // add closing --> closing < open
    // if open == n --> only be able to add closings now
    int open = 0;
    int close = 0;
    stack<char> curr;
    vector<string> v;
    helper(open, close, n, curr, v);
    return v;
}