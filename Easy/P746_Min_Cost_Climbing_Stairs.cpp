int minCostClimbingStairs(vector<int>& cost) {
        // start from the end and us DP
        // DP Recurrance: min cost for reaching the top floor from where you are at
        // return min(DP[0], DP[1]);

        int n = cost.size();
        vector<int> dp(n);
        dp[n - 1] = cost[n - 1]; // min cost from index n to the top;
        dp[n - 2] = cost[n - 2];

        for (int i = n - 3; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }

        return min(dp[0], dp[1]);
}