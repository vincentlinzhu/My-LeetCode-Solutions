#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <cmath>

void sortColors(vector<int>& nums) {
    vector<int> v;
    vector<int>::iterator itr=v.begin();
    for (itr=nums.begin(); itr!=nums.end();itr++){
        if(*itr==0){
            v.push_back(*itr);
        }
    }
    vector<int>::iterator i=v.begin();
    for (i=nums.begin(); i!=nums.end();i++){
        if(*i==1){
            v.push_back(*i);
        }
    }
    vector<int>::iterator it=v.begin();
    for (it=nums.begin(); it!=nums.end();it++){
        if(*it==2){
            v.push_back(*it);
        }
    }
    nums=v;
}
int main(){
    
    return 0;
}
