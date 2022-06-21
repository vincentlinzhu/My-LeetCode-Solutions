#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getSum(int a, int b) {
    int addition = 0;
    int carry = 0;
    while (true) {
        //Find positions that nend a carry
        carry = a & b;
        if (carry == 0) {
            break;
        }
        
        //Find actual sum
        addition = a ^ b;
        
        //next iteration
        a = addition;
        b = (unsigned int)carry << 1; //or b = (carry & 0xffffffff) << 1;
    }
    int sum = a ^ b;
    return  sum;
}

int main(int argc, const char * argv[]) {    
    int x = 1;
    int y = -1;
    cout << getSum(x, y) << endl;
    return 0;
}
