#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <cmath>

bool isPalindrome(int x) {
    int m, r;
    long rev=0;
    m = x;
    while (x>0){
        r = x%10;
        x = x/10;
        rev = (rev*10)+r;
    }
    cout<< rev << endl;
    if (rev == m){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    
    return 0;
}
