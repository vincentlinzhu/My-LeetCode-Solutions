#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> m;
    for(int i = 0; i<s.length(); i++){
        m[s[i]]++;
    }
    for(int i = 0; i<s.length(); i++){
        if(m[s[i]] == 1){
            return i + 1;
        }
    }
    return -1;
}

int main() {
    string s = "statistics";
    cout << firstUniqChar(s) << endl;
    return 0;
}
