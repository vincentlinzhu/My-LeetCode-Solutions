int findDuplicate(vector<int>& nums) {
    int slow = 0;
    int fast = 0;

    // Phase 1
    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) {
            break;
        }
    }

    // Phase 2
    int slow2 = 0;
    while (true) {
        slow2 = nums[slow2];
        slow = nums[slow];
        if (slow == slow2) {
            break;
        }
    }

    return slow;
}