// DP Method:
int numDecodings(string s) {
    if (s[0] == '0') {
        return 0;
    }
    
    int n = s.size();
    
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        int ones = stoi(s.substr(i - 1, 1));
        if (ones >= 1 && ones <= 9) {
            dp[i] += dp[i - 1];
        }
        int tens = stoi(s.substr(i - 2, 2));
        if (tens >= 10 && tens <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    
    return dp[n];
}

// Brute Force:
int numDecodings(string s) {
    // iterate through one time.
    // have a count variable to keep track
    // edge cases:
        // if the first number is a 0 in a 2 digit scenario, that's NOT valid
        // if the first number is over 2 in a 2 digit case, NOT valid
        // if the second number is over 6 in a 2 digit scenario, NOT valid
    // There are only 2 scenario: build a decision tree, and try to minimize Overlap/Repitition
    // Method: use recursion on each substring once a char is already decoded

    int count = 0;

    // base case:
    if (s.size() == 0) {
        return 1;
    }
    if (s.size() == 1) {
        if (stoi(s.substr(0, 1)) < 10 && stoi(s.substr(0, 1)) > 0) {
            return 1;
        }
        else {
            return 0;
        }
    }

    // 1 digit case:
    if (stoi(s.substr(0, 1)) < 10 && stoi(s.substr(0, 1)) > 0) {
        count += numDecodings(s.substr(1, s.size() - 1));
        // Overlap/Repitition: if I remove 1 digit twice, the remaining string will be the same as when I removed 2 digits the time before
    }

    // 2 digit case:
    if (stoi(s.substr(0, 2)) < 27 && stoi(s.substr(0, 2)) > 9) {
        count += numDecodings(s.substr(2, s.size() - 2));
    }
    
    return count;
}