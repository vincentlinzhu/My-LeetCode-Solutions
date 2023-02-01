int minCost(string colors, vector<int>& neededTime) {
    int res = 0;
    int cur = 0;

    for (int i = 0; i < colors.length(); i++) {
        if (i > 0 && colors[i] != colors[i - 1]) {
            cur = 0;
        }
        res += min(cur, neededTime[i]);
        cur = max(cur, neededTime[i]);
    }

    return res;
}