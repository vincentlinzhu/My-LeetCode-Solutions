#include <iostream>
using namespace std;
#include <vector>

bool canWinNim(int n) {
    if (n<4){
        return true;
    }
    else if (n%4 ==0){
        return false;
    }
    else{
        return true;
    }
}

int main() {
    int v = 4;
    cout << canWinNim(v) << endl;
    return 0;
}
