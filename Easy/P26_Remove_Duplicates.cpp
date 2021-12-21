#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

int removeDuplicates(vector<int>& nums) {
    vector<int> v;
    for(int i=0;i<nums.size();i++){
        if(count(v.begin(),v.end(),nums[i])==0){
            v.push_back(nums[i]);
        }
    }
    nums=v;
    return v.size();
}

int main(){
    //vector<int> nums={1,1,2};
    //cout<<removeDuplicates(nums)<<endl;
    return 0;
}