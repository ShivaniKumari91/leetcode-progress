class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
          int n = prices.size();

        // ahead = dp[ind + 1]
        // cur   = dp[ind]
        vector<int> ahead(2, 0);
        vector<int> cur(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {

            for (int buy = 0; buy <= 1; buy++) {

                int profit = 0;

                if (buy == 1) {

                    // Buy
                    int buyStock = -prices[ind] + ahead[0];

                    // Don't Buy
                    int notBuy = ahead[1];

                    cur[buy] = max(buyStock, notBuy);
                }

                else {

                    // Sell
                    int sell = prices[ind] - fee + ahead[1];

                    // Don't Sell
                    int notSell = ahead[0];

                    cur[buy] = max(sell, notSell);
                }

                
            }

            // Current row becomes next row
            ahead = cur;
        }

        return ahead[1];
     
        
    }
};