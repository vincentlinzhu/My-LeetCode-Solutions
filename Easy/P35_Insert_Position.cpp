#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

int searchInsert(vector<int>& nums, int target) {
    int l=0, h=(int)nums.size()-1, mid, res=0;
    //use binary search for O(log n) time complexity
    while(l<=h){
        mid = (l+h)/2;
        if (target==nums[mid]){
            return mid;
        }
        if(target>nums[mid]){
            l=mid+1;
            res=mid+1;
        }
        else{
            h=mid-1;
            res=mid;
        }
    }
    return res;
}

int main(){
    //vector<int> v={1,3,5,6};
    //cout<<searchInsert(v, 2)<<endl;
    return 0;
}
