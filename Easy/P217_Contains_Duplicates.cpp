#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

// bool containsDuplicate(vector<int>& nums) {
//     for (int i = 0; i< nums.size(); i++) {
//         for (int j = i + 1; j < nums.size(); j++) {
//             if (nums.at(i) == nums.at(j)) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// bool containsDuplicate(vector<int>& nums) {
//     map<int, int> m;
//     for (int i = 0; i < nums.size(); i++) {
//         auto it = m.find(nums.at(i));
//         if (it == m.end()) {
//             m.insert(pair<int,int>(nums.at(i), 1));
//         }
//         else {
//             return true;
//         }
//     }
//     return false;
// }

bool containsDuplicate(vector<int>& nums) {
    std::sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums.at(i) == nums.at(i+1)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> v = {1,2,3,1};
    cout << containsDuplicate(v) << endl;
}