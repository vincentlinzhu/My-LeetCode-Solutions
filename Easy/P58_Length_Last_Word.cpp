#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <cmath>

int lengthOfLastWord(string s) {
    int length=0;
    for (int i=s.length()-1; i>=0; i--){
        if ((s.substr(i,1).compare(" ")==0) && (i==s.length()-1)){
            i--;
        }
        if (s.substr(i,1).compare(" ")!=0){
            length++;
        }
        if ((s.substr(i,1).compare(" ")==0) && (s.substr(i+1,1).compare(" ")!=0)){
            break;
        }
    }
    return length;
}

int main(){
    string v="a";
    cout<<lengthOfLastWord(v)<<endl;
    return 0;
}