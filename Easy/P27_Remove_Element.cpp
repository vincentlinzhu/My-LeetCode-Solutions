#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

int removeElement(vector<int>& nums, int val) {
    vector<int>::iterator itr=nums.begin();
    for (itr=nums.begin(); itr!=nums.end(); itr++){
        if (*itr==val){
            nums.erase(itr);
            itr--;
        }
    }
    return nums.size();
}

int removeElement2(vector<int>& nums, int val) {
    int l = 0;
    int r = nums.size() - 1;
    if (nums.size() == 0) {
        return 0;
    }
    while (l < r){
        while (nums[r] == val) {
            r--;
            if (r < 0) {
                return 0;
            }
        }
        if (l < r && nums[l] == val){
            nums[l] = nums[l] + nums[r];
            nums[r] = nums[l] - nums[r];
            nums[l] = nums[l] - nums[r];
            r--;
        }
        l++;
    }

    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) {
            break;
        }
        res++;
    }
    return res;
}

int main(){
    //vector<int> v={1,2,3,4,3,3,3,3,5};
    //int x=3;
    //cout<<removeElement(v, x)<<endl;
    
    return 0;
}
