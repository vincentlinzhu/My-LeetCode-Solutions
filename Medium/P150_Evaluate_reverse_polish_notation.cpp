int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    int val1, val2;

    for (auto x : tokens) {
        if (x == "+" || x == "-" || x == "*" || x == "/") {
            val1 = nums.top();
            nums.pop();
            val2 = nums.top();
            nums.pop();
            if (x == "+") {
                nums.push(val2 + val1);
            } else if (x == "-") {
                nums.push(val2 - val1);
            } else if (x == "*") {
                nums.push(val2 * val1);
            } else {
                nums.push(val2 / val1);
            }
        } else {
            nums.push(stoi(x));
        }
    }

    return nums.top();
}