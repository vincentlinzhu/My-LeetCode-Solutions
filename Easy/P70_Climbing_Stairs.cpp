#include <iostream>
using namespace std;
#include <vector>

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    vector<int> v(n, 0);
    v[0] = 1;
    v[1] = 2;
    for (int i = 2; i < n; i++) {
        v[i] = v[i - 1] + v[i - 2];
    }

    return v[n - 1];
}

int main(){
    cout << climbStairs(5) << endl;
    return 0;
}