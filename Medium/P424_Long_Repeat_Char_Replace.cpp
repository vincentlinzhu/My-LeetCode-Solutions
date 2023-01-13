#include <iostream>
#include <vector>
#include <map>

using namespace std;

int characterReplacement(string s, int k) {
    int l = 0;
    int r = 0;
    map<char, int> m;
    int mostFrequent = 0;
    int res = 0;
    
    while (r < s.length()) {
        map<char, int>::iterator it = m.find(s[r]);
        if (it == m.end()) {
            m.insert(pair<char, int>(s[r], 1));
        } else {
            it->second++;
        }
        it = m.find(s[r]);
        mostFrequent = max(it->second, mostFrequent);

        if ((r - l + 1 - mostFrequent) > k) {
            it = m.find(s[l]);
            it->second--;
            l++;
        }
        res = max(res, r - l + 1);
        r++;
    }

    return res;
}

int main() {
    string s = "AABABBA";
    cout << characterReplacement(s, 1) << endl;
    return 0;
}
