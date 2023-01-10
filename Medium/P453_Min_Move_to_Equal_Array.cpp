#include <iostream>
#include <vector>
#include <set>

using namespace std;

int minMoves(vector<int>& nums) {
    int sum = 0;
    int min = INT_MAX;

    for (int i =0; i < nums.size(); i++) {
        sum += nums.at(i);
        if (nums.at(i) < min) {
            min = nums.at(i);
        }
    }

    return (sum - (min * nums.size()));
}


int main() {
    vector<int> nums {5, 6, 7, 8};
    cout << minMoves(nums) << endl;
    
    return 0;
}