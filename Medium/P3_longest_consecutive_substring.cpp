#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    set<char> charSet;
    int maxLength = 0;
    int l = 0;
    int r = 0;
    while (r < s.length()) {
        while (charSet.find(s[r]) != charSet.end()) {
            set<char>::iterator it = charSet.find(s[l]);
            charSet.erase(it);
            l++;
        }
        charSet.insert(s[r]);
        maxLength = max(maxLength, r - l + 1);
        r++;
    }
    return maxLength;
}

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m;
    int maxLength = 0;
    int l = 0;
    int r = 0;
    while (r < s.length()) {
        unordered_map<char, int>::iterator it = m.find(s[r]);
        if (it == m.end()) {
            m.insert(pair<char, int>(s[r], r));
            if (r - l + 1 == 10) {
                cout << r << " " << l << endl;
                // unordered_map<char, int>::iterator itr;
                // for (itr = m.begin(); itr != m.end(); itr++) {
                //     cout<<itr->first<<" "<<itr->second<<endl;
                // }
            }
            maxLength = max(maxLength, r - l + 1);
        } else {
            l = it->second + 1;
            m.erase(m.find(s[r]), m.end());
            m.insert(pair<char, int>(s[r], r));
        }
        r++;
    }
    return maxLength;
}


int main() {
    string s = "vtdqnitimrzllopyeq";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}