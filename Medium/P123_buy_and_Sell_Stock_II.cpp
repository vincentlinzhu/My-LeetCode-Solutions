int maxProfit(vector<int>& prices) {
    int l = 0;
    int r = 0;
    int maxProfit = 0;
    while (r < prices.size()) {
        if (prices[l] <  prices[r]) {
            maxProfit += prices[r] - prices[l];
        }
        l = r;
        r++;
    }
    return maxProfit;
}