#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((n & mask) >= 1) {
            count ++;
        }
        mask = (unsigned)mask << 1;
    }
    return count;
}

int main() {
    uint32_t x = 00000000000000000000000000001011;
    cout << hammingWeight(x) << endl;
}