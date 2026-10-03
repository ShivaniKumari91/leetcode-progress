class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

              

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base Case
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {

            for (int buy = 0; buy <= 1; buy++) {

                int profit = 0;

                if (buy == 1) {

                    // Buy
                    int buyStock = -prices[ind] + dp[ind + 1][0];

                    // Don't Buy
                    int notBuy = dp[ind + 1][1];

                    dp[ind][buy] = max(buyStock, notBuy);
                }

                else {

                    // Sell
                    int sell = prices[ind] - fee + dp[ind + 1][1];

                    // Don't Sell
                    int notSell = dp[ind + 1][0];

                    dp[ind][buy] = max(sell, notSell);
                }

               
            }
        }

        return dp[0][1];
        
    }
};