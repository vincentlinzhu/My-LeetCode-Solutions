int maxArea(vector<int>& height) {
    int maxAmount = 0;
    int l = 0;
    int r = height.size() - 1;

    while (l < r) {
        int minHeight = 0;
        minHeight = min(height[l], height[r]);
        maxAmount = max(maxAmount, minHeight * (r - l));
        if (minHeight == height[l]) {
            l++;
        } else {
            r--;
        }
    }
    return maxAmount;
}