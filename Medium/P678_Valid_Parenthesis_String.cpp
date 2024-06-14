bool checkValidString(string s) {
    stack<int> s1;
    stack<int> s2;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            s1.push(i);
        } else if (s[i] == ')') {
            if (!s1.empty()) {
                s1.pop();
            } else if (!s2.empty()) {
                s2.pop();
            } else {
                return false;
            }
        } else {
            s2.push(i);
        }
    }

    if (s1.empty()) {
        return true;
    } else {
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() < s2.top()) {
                s1.pop();
                s2.pop();
            } else {
                return false;
            }
        }
    }

    if (s1.empty()) {
        return true;
    }

    return false;

}