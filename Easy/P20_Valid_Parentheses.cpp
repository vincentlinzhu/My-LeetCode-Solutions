#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <cmath>
#include <string>

bool isValid(string s) {
    if ((s.length()%2)!=0){
        return false;
    }
    while((s.find("()") != string::npos)||(s.find("{}") != string::npos)||(s.find("[]") != string::npos)){
        if(s.find("()") != string::npos){
            s.erase((s.find("()")),2);
        }
        if(s.find("{}") != string::npos){
            s.erase((s.find("{}")),2);
        }
        if(s.find("[]") != string::npos){
            s.erase((s.find("[]")),2);
        }
    }
    if(s.length()==0){
        return true;
    }
    return false;
}
int main(){
    string s="(([]){})";
    cout<<isValid(s)<<endl;
    
    return 0;
}