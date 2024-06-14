bool canPartition(vector<int>& nums) {
    // what are all the sums that are possible for a vector and its subvectors
    // store these sums in dp
    // does the next value plus one of these sums = target (sum(nums)/2)

    int target = 0;
    for (auto x : nums) {
        target += x;
    }
    if (target % 2 != 0) {
        return false;
    } else {
        target /= 2;
    }

    set<int> dp;
    dp.insert(0);
    set<int> nextDP = dp;

    for (int i = nums.size() - 1; i >= 0; i--) {
        nextDP = dp;
        for (auto sum : dp) {
            if (sum + nums[i] == target) {
                return true;
            }
            nextDP.insert(sum + nums[i]);
        }
        dp = nextDP;
    }

    return false;
}