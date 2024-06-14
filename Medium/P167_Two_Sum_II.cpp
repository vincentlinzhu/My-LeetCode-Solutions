vector<int> twoSum(vector<int>& numbers, int target) {
    // one pointer on one end, and one on the other
    // shift the left or the right pointer like a binary search based on the sum relative to the target
    vector<int> res (2, 0);
    int r = numbers.size() - 1;
    int l = 0;
    while (r > l) {
        if (numbers[l] + numbers[r] == target) {
            res[0] = l + 1;
            res[1] = r + 1;
            return res;
        } else if (numbers[l] + numbers[r] > target) {
            r--;
        } else {
            l++; 
        }
    }

    return res;
}