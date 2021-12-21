#include <iostream>
using namespace std;
#include <vector>

//Method 1: Time Complexity O(n^2)
int maxSubArray(vector<int>& nums) {
    int sum=nums[0];
    int max=sum;
    for (int i=0; i<nums.size(); i++){
        sum=nums[i];
        if (sum>max){
            max=sum;
        }
        for(int j=i+1; j<nums.size(); j++){
            sum+=nums[j];
            if (sum>max){
                max=sum;
            }
        }
    }
    return max;
}

//Method 2: Dynamic Programming (Kadane's Algorthim) = Time Complexity O(n)
// Kadane's Algorithm: maxSum[i] = max( A[i], A[i] + maxSum[i - 1] )
int maxSubArray(vector<int>& nums) {
    /*2 options that goes into our comparison for max:
        1. Start a new subarray with this item
        2. Continue from the best we can do before the index we are on
     */
    int Max=INT_MIN;
    int localMax=0;
    for (int i=0; i<nums.size();i++){
        localMax=max(nums[i], localMax+nums[i]);
        if(localMax>Max){
            Max=localMax;
        }
    }
    return Max;
}

int main() {
    //vector<int> v={-2,1};
    //cout <<maxSubArray(v)<<endl;
    return 0;
}
