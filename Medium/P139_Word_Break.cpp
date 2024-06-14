// Method 1: DP Caching + Brute Force:
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1);
    dp[n] = true;

    for (int i = n - 1; i >= 0; i--) {
        for (auto w : wordDict) {
            if (i + w.size() <= s.size() && w == s.substr(i, w.size())) {
                dp[i] = dp[i + w.size()];
            }  
            if (dp[i]) {
                break;
            }
        }
    }

    return dp[0];
}

// Method 2: Brute Force:
bool wordBreak(string s, vector<string>& wordDict) {
    if (s.size() == 0) {
        return true;
    }
    
    unordered_set<string> words;
    for (auto word : wordDict) {
        words.insert(word);
    }

    vector<string> valid;
    for (int i = 0; i < wordDict.size(); i++) {
        if (wordDict[i].size() <= s.size()) {
            string test = s.substr(0, wordDict[i].size());
            if (words.find(test) != words.end()) {
                valid.push_back(wordDict[i]);
            }
        }
    }

    for (auto validWord : valid) {
        string temp = s.substr(validWord.size(), s.size() - validWord.size());
        if (wordBreak(temp, wordDict)){
            return true;
        }
    }

    return false;
}

// Method 3: DP Bottom up
bool wordBreak(string s, vector<string>& wordDict) {
    // iterate through the vector and shrink the size of the string
    // how do use a vector to keep track of the sub problems:
        // recurrance relation: dp(map){substring, bool} = w 
    unordered_set<string> words;
    for (auto word : wordDict) {
        words.insert(word);
    }

    vector<bool> dp(s.size() + 1);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (dp[j]) {
                string sub = s.substr(j, i - j);
                if (words.find(sub) != words.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[s.size()];
}