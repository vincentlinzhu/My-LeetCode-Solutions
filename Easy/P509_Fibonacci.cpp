#include <iostream>
using namespace std;
#include <vector>

//Method 1: Recurssion
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int v = 6;
    cout << fib(v) << endl;
    return 0;
}
