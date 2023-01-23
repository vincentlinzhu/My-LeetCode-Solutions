#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isLowerCaseVal (char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

vector<int> hasVowels(vector<string> strArr, vector<string> query) {
    vector<int> res;
    vector<int> temp;
    int count = 0;

    for (int i = 0; i < strArr.size(); i++) {
        if (isLowerCaseVal(strArr[i][0]) && isLowerCaseVal(strArr[i][strArr[i].length() - 1])) {
            count++;
            temp.push_back(count);
        } else {
            temp.push_back(0);
        }
    }
    
    for (int i = 0; i < query.size(); i++) {
        int l = stoi(query[i].substr(0, 1));
        int r = stoi(query[i].substr(query[i].length() - 1, 1));
        while (temp[l - 1] == 0) {
            l++;
        }
        while (temp[r - 1] == 0) {
            r--;
        }
        if (l == r) {
            if (isLowerCaseVal(strArr[l - 1][0]) && isLowerCaseVal(strArr[l - 1][strArr[l - 1].length() - 1])) {
                res.push_back(1);
            } else {
                res.push_back(0);
            }
        } else {
            res.push_back(temp[r - 1] - temp[l - 1] + 1);
        }
    }
    
    return res;
}

int main() {
    vector<string> y {"aba", "bdc", "ece", "a", "ee"};
    vector<string> x {"1-3", "2-5", "2,2"};
    vector<int> res = hasVowels(y,x);
    for (int i = 0; i < x.size(); i++) {
        cout << res.at(i) << endl;
    }
    return 0;
}