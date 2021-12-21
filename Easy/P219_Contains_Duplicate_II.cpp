#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <cmath>

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set <int> us;
    for (int i=0; i<nums.size(); i++){
        if (us.count(nums[i])){
            return true;
        }
        //Or
        /*if (us.find(nums[i])!=us.end()){
            return true;
        }*/
        us.insert(nums[i]);
        if(i>=k){
            us.erase(nums[i-k]);
        }
    }
    return false;
}
bool containsNearbyDuplicateA(vector<int>& nums, int k) {
    for (int i=0; i<k; i++){
        for (int j=i+1; j<nums.size();j++){
            if ((nums[i]==nums[j])&&(abs(i-j))<=k){
                return true;
            }
        }
    }
    return false;
}
bool containsNearbyDuplicateB(vector<int>& nums, int k) {
    if (nums.size() <= 1) {
        return false;
    }
    for (int i = 0; i < nums.size(); i++) {
        for (int j=i+1; j<=i+k && j < nums.size(); j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

int main(){
    //vector<int> v={1,2,3,1};
    //cout<<containsNearbyDuplicate(v,3)<<endl;
    
    return 0;
}
