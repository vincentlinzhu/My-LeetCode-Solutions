#include <iostream>
using namespace std;
#include <cmath>
#include <cstring>
#include <vector>
#include <map>

//Method 1:
vector<int> twoSum1(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                v.push_back(m[target-nums[i]]);
                v.push_back(i);
                return v;
            }
            m[nums[i]]=i;
        }
        return v;
    }
//Method 2:
vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> result;
    for(int i=0;i<nums.size();i++){
        int Diff=target-nums[i];
        int j;
        for (j=i+1; j<nums.size(); j++){
            if(nums[j]==Diff){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

int main(){
    vector<int> num;
    num.push_back(2);
    num.push_back(7);
    num.push_back(11);
    num.push_back(15);
    vector<int> v1=twoSum1(num, 9);
    for (int x=0; x<v1.size(); x++){
        cout<<v1[x]<<endl;
    }
    vector<int> v2=twoSum2(num, 9);
    for (int x=0; x<v2.size(); x++){
        cout<<v2[x]<<endl;
    }
    return 0;
}
