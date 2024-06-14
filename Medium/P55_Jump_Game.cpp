//Method 0:
bool canJump(vector<int>& nums) {
    int goal = nums.size() - 1;

    for (int i = nums.size() - 1; i >= 0; i--) {
        if (i + nums[i] >= goal) {
            goal = i;
        }
    }

    if (goal == 0) {
        return true;
    }
    return false;
}
//Method 1: iterative (Greedy)
bool canJump(vector<int>& nums) {
    int reachable = 0; // reachable is the last index reachable

    for (int i = 0; i < nums.size(); i++) {
        if (i > reachable) {
            return false;
        }
        reachable = max(reachable, i + nums[i]);
        if (reachable >= nums.size() - 1) {
            break;
        }
    }

    return true;
}
//Method 2: Recursion (Poor Memory)
bool reachable(int index, vector<int>& currNums) {
    if (index == 0) {
        return true;
    }

    for (int i = currNums.size() - 2; i >= 0; i--) {
        if (i + currNums[i] >= currNums.size() - 1) {
            currNums = updateNums(currNums.begin(), currNums.begin() + i + 1);
            return reachable(i, updateNums);
        }
    }

    return false;
}
bool canJump(vector<int>& nums) {
    // you can jump a variable amount of distance
    // then you need to keep track of what the furthest per choice is
    // can this index be reached, work back to the possible choice
    // Then can this varibale be reached
    // iterate backwards until you find a position that can jump directly to the end
    // then run the function recursively on that position.
    return reachable(nums.size() - 1, nums);
}