#include <iostream>
using namespace std;
#include <vector>

int rob(vector<int>& nums) {
    int rob1 = 0;
    int rob2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        temp = max(nums[i] + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    
    return rob2;
}

int main(){
    vector<int> v = {1,2,3,1};
    cout << rob(v) << endl;
    return 0;
}