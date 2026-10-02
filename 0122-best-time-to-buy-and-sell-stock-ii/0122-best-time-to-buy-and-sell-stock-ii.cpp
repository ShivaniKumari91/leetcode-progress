
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices,
          vector<vector<int>>& dp) {

        int n = prices.size();

        // Base Case
        if (ind == n)
            return 0;

        // Already calculated
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;

        if (buy == 1) {

            // We can BUY
            int take = -prices[ind] + f(ind + 1, 0, prices, dp);

            // We don't BUY
            int notTake = f(ind + 1, 1, prices, dp);

            // Choose maximum profit
            profit = max(take, notTake);
        }

        else {

            // We can SELL
            int sell = prices[ind] + f(ind + 1, 1, prices, dp);

            // We don't SELL
            int notSell = f(ind + 1, 0, prices, dp);

            // Choose maximum profit
            profit = max(sell, notSell);
        }

        // Store the calculated profit
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, prices, dp);
    }
};


