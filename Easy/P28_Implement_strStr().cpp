#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

int strStr(string haystack, string needle) {
    if(needle.length()==0){
        return 0;
    }
    else{
        for(int i=0; i<haystack.length()-needle.length()+1; i++){
            if(haystack.substr(i,needle.length()).compare(needle)==0){
                return i;
                //break;
            }
        }
    }
    return -1;
}

int main(){
    string s1="Hello";
    string s2="l";
    cout<<strStr(s1,s2)<<endl;
    return 0;
}
