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

int main(){
    //vector<int> v={1,2,3,4,3,3,3,3,5};
    //int x=3;
    //cout<<removeElement(v, x)<<endl;
    
    return 0;
}
