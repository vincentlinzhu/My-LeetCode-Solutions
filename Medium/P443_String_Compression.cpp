#include <iostream>
#include <vector>
#include <map>

using namespace std;

int compress(vector<char>& chars) {
    if (chars.size() == 0) {
        return 0;
    }
    int count = 1;
    int l = 0;
    int r = 0;
    vector<char> vec;
    string result = "";
    
    for (int i = 0; i < chars.size(); i++) {
        vec.push_back(chars.at(i));
    }
    chars.clear();
    
    while (r < vec.size()) {
        r++;
        if (r < vec.size() && (vec.at(l) == vec.at(r))) {
            count++;
        }
        else if (count > 1) {
            chars.push_back(vec.at(l));
            string num = to_string(count);
            for (int i = 0; i < num.length(); i++) {
                chars.push_back(num.at(i));
            }
            l = r;
            count = 1;
        }
        else {
            chars.push_back(vec.at(l));
            l = r;
            count = 1;
        }
    }
    
    return chars.size();
}


int main() {
    vector<char> chars {'a','a','b','b','c','c','c'};
    cout << compress(chars) << endl;
    return 0;
}
