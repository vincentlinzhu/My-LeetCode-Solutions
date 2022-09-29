#include <iostream>
#include <vector>
#include <map>

using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums) {
//     int l = 0;
//     int r = nums.size() - 1;
//     vector<vector<int>> v;
//     map<int, int> m;

//     for (int i = 0; i < nums.size(); i++) {
//         int comp = 0 - nums.at(i);
//         if (m.find(comp) != m.end()) {
//             v.push_back(nums.at(i))
//         }
//     }
// }

vector< vector<int> > threeSum(vector<int>& nums) {
    vector< vector<int> > v;

    int n = nums.size();
    if (n < 3) {
        return v;
    }

    sort(nums.begin(), nums.end());   

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            break;
        } 
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }

        int l = i + 1;
        int r = nums.size() - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum < 0) {
                l++;
            } else if (sum > 0) {
                r--;
            } else {
                v.push_back({nums[i], nums[l], nums[r]});
                
                while (l < r && nums[l] == nums[l + 1]) {
                    l++;
                }
                l++;
                
                while (l < r && nums[r - 1] == nums[r]) {
                    r--;
                }
                r--;
            }
        }
    }

    return v;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    for (int i = 0; i < threeSum(nums).size(); i++) {
        for (int j = 0; j < threeSum(nums).at(i).size(); i++) {
            cout << threeSum(nums).at(i).at(j) << endl;
        }
    }
    return 0;
}