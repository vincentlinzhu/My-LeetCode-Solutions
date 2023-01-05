#include <iostream>
#include <vector>
#include <set>

using namespace std;

int longestConsecutiveClean(vector<int>& nums) {
    unordered_set<int>s(nums.begin(), nums.end());
    int longest = 0;
    for(auto &n: s){
        //if this is the start of the sequence
        if(!s.count(n - 1)){
            int length = 0; 
            while(s.count(n + length))
                length++;
            longest = max(longest, length);
        } 
    }
    return longest;
}

int longestConsecutive(vector<int>& nums) {
    int longest = 0;
    set<int> numSet;
    for (int i = 0; i < nums.size(); i++) {
        numSet.insert(nums.at(i));
    }
    
    for (int i = 0; i < nums.size(); i++) {
        set<int>::iterator it = numSet.find(nums.at(i) - 1);
        if (it == numSet.end()) {
            int length = 0;
            while (numSet.count(nums.at(i) + length) != 0) {
                length++;
            }
            longest = max(length, longest);
        }
    }
    
    return longest;
}

set<int> printSet(vector<int>& nums) {
    set<int> numSet;
    for (int i = 0; i < nums.size(); i++) {
        numSet.insert(nums.at(i));
    }
    
    return numSet;
}


int main() {
    vector<int> nums {0, 4, 8, 1, 3, 5, 6, 7, 2};
//    vector<int> nums {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;
    return 0;
}
