vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> answer;
    int prev = 1;
    int next = 1;

    for (int i = 1; i < nums.size(); i++) {
        answer[i] = nums[i] * prev;
        prev = nums[i] * prev;
    }   
    for (int i = nums.size() - 1; i >= 0; i--) {
        answer[i] = next;
        next = answer[i] * next;
    }

    return answer;
}

//Extra Memory:
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prefix (nums.size(), 1);
    vector<int> postfix (nums.size(), 1);
    vector<int> answer;

    for (int i = 1; i < nums.size(); i++) {
        prefix[i] = nums[i - 1] * prefix[i - 1];
    }   
    for (int i = nums.size() - 2; i >= 0; i--) {
        postfix[i] = nums[i + 1] * postfix[i + 1];
    }
    for (int i = 0; i < nums.size(); i++) {
        answer.push_back(prefix[i] * postfix[i]);
    }

    return answer;
}