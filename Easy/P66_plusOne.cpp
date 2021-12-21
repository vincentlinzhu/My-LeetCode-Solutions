#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> out = {1};
    digits[digits.size() - 1] ++;
    if (digits[digits.size()-1] == 10){
        for (int i = digits.size() - 1; i >= 0; i--){
            if ((i == 0) && digits[i] == 10) {
                digits[i] = 0;
                out.insert(out.end(), digits.begin(), digits.end());
                return out;
            }
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[i-1] ++;
            }
        }
    }
    return digits;
}

int main(int argc, char *argv[])  {
    vector<int> v = {8,9,9,9};
    vector<int> out = plusOne(v);
    cout << "[" << out[0];
    for (int i = 1; i < out.size(); i++){
        cout << "," << out[i];
    }
    cout << "]" << endl;
    return 0;
}

