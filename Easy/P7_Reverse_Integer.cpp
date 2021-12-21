#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <cmath>

//Method 1:
int reverse1(int x) {
    int r,n;
    long rev=0;
    n=abs(x);
    while(n>0){
        r = n%10;
        n = n/10;
        rev = (rev*10)+r;
    }
    if (x<0){
        if (rev<=pow(2,31)){
            return -1*rev;
        }
    }
    else {
        if (rev<=pow(2,31)-1){
            return rev;
        }
    }
    return 0;
}

//Method 2:
int reverse2(int x) {
    long y=abs(x);
    vector<long> v;
    while(y!=0){
        v.push_back(y%10);
        y-=(y%10);
        y/=10;
    }
    long rev=0;
    vector<long>::iterator itr=v.begin();
    for (itr=v.begin(); itr!=v.end();itr++){
        rev+=*itr;
        rev*=10;
    }
    if (x<0){
        if (rev/10<=pow(2,31)){
            return -1*rev/10;
        }
    }
    else {
        if (rev/10<=pow(2,31)-1){
            return rev/10;
        }
    }
    return 0;
}

int main(){
    
    return 0;
}
