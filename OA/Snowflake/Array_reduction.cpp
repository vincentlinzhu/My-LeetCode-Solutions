#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'getMaximum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> getMaxArray(vector<int> arr) {
    vector<int> result;
    for (int k = arr.size(); k >= 0; k--) {
        vector<int> temp;
        while (arr.size() > 0) {
            map<int, int> m;
            int mex = 0;
            for (int i = 0; i < k; i++) {
                m.insert(pair<int, int>(arr[i], i));
            }
            map<int, int>::iterator it = m.find(mex);
            while (it == m.end()) {
                mex++;
                it = m.find(mex);
            }
            temp.push_back(mex);
            arr = vector<int>(arr.begin() + k, arr.end());
        }
        result = max(temp, result);
    }
    
    return result;
}

int main() {
    vector<int> v = {0, 1, 1, 0};
    vector<int> res = getMaxArray(v);
    for (int i = 0; i < v.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
