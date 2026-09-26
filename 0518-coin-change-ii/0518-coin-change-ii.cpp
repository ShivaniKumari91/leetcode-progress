class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<long long>> dp(
            n, vector<long long>(amount + 1, 0)
        );

        // Base case
        for(int target = 0; target <= amount; target++) {
            if(target % coins[0] == 0)
                dp[0][target] = 1;
        }

        for(int ind = 1; ind < n; ind++) {
            for(int target = 0; target <= amount; target++) {

                long long notTake = dp[ind-1][target];

                long long take = 0;

                if(coins[ind] <= target) {
                    take = dp[ind][target - coins[ind]];
                }

                long long ways = take + notTake;

                // Keep DP value within int range
                dp[ind][target] = min(ways, 1LL * INT_MAX);
            }
        }

        return (int)dp[n-1][amount];
    }
};