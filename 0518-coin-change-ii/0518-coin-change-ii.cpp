class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(amount + 1, 0));

        // amount = 0 → exactly 1 way
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++) {
            for(int target = 1; target <= amount; target++) {

                int notTake = dp[i - 1][target];

                int take = 0;

                if(coins[i - 1] <= target) {
                    take = dp[i][target - coins[i - 1]];
                }

                long long ways = 1LL * take + notTake;

                dp[i][target] = min(ways, 1LL * INT_MAX);
            }
        }

        return dp[n][amount];
    }
};