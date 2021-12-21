#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <cmath>

string longestCommonPrefix(vector<string>& strs) {
    string LCP="";
    long minlen=strs[0].length();
    for (int j=1;j<strs.size();j++){
        if (strs[j].length()<minlen){
            minlen=strs[j].length();
        }
    }
    for (int i=0;i<minlen;i++){
        int count=0;
        for (int k=1;k<strs.size();k++){
            if((strs[0].substr(i,1)).compare(strs[k].substr(i,1))==0){
                count++;
            }
        }
        if(count==strs.size()-1){
            LCP+=strs[0].substr(i,1);
        }
        else{
            break;
        }
    }
    return LCP;
}

int main(){
    //vector<string> v={"flower","flow","flight"};
    //cout<<longestCommonPrefix(v)<<endl;
    return 0;
}
