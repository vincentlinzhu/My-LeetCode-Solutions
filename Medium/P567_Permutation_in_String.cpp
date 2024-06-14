bool checkInclusion(string s1, string s2) {
    // map of all letters of s1
    // sliding window through s2 to check if is it in s1
    if (s1.size() > s2.size()) {
        return false;
    }

    unordered_map<char, int> letters;
    for (auto x : s1) {
        if (letters.count(x) == 0) {
            letters[x] = 1;
        }
        else {
            letters[x]++;
        }
    }

    int l = 0;
    int r = s1.size() - 1;
    bool matches = false;
    unordered_map<char, int> temp;
    while (r < s2.size()) {
        temp = letters;
        for (int i = l; i <= r; i++) {
            if (temp.count(s2[i]) && temp[s2[i]] != 0) {
                temp[s2[i]]--;
                matches = true;
            } else {
                matches = false;
                break;
            }
        }
        if (matches) {
            return true;
        }
        l++;
        r++;
    }

    return false;
}