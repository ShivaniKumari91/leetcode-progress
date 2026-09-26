class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<int> prev(amount + 1, 0);
        vector<int> cur(amount + 1, 0);

        // Base case: only coins[0] available
        for(int target = 0; target <= amount; target++) {
            if(target % coins[0] == 0)
                prev[target] = 1;
        }

        for(int ind = 1; ind < n; ind++) {

            for(int target = 0; target <= amount; target++) {

                // Don't take current coin
                int notTake = prev[target];

                // Take current coin
                int take = 0;

                if(coins[ind] <= target) {
                    take = cur[target - coins[ind]];
                }

                long long ways = 1LL * take + notTake;

                cur[target] = min(ways, 1LL * INT_MAX);
            }

            prev = cur;
        }

        return prev[amount];
    }
};