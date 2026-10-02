class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(5,0));

        for(int trans = 0; trans <= 4; trans++){
            dp[n][trans] = 0;
        }

        for(int ind = 0; ind<n; ind++){
            dp[ind][4] = 0;
        }

        for(int ind = n-1; ind>=0; ind--){
            for(int transaction = 3; transaction >= 0;transaction--){
                if(transaction % 2 == 0){
                    dp[ind][transaction] = max(-prices[ind] + dp[ind + 1][transaction + 1],
                                                0 + dp[ind + 1][transaction]);
                }
                else{
                    dp[ind][transaction] = max(prices[ind] + dp[ind+1][transaction + 1],
                                                0 + dp[ind + 1][transaction]);
                }
            }
        }

        return dp[0][0];

       
        
    }
};