class Solution {
public:
    int f(int ind, int transaction,vector<vector<int>> &dp,vector<int> &prices){
        if(ind == prices.size() || transaction == 4) return 0;

        if(dp[ind][transaction] != -1) return dp[ind][transaction];

        if(transaction % 2 == 0){
            return dp[ind][transaction] = max(-prices[ind] + f(ind + 1,transaction + 1,dp,prices),0 + f(ind + 1,transaction,dp,prices));
        }

        else{
            return dp[ind][transaction] = max(prices[ind] + f(ind + 1,transaction + 1,dp,prices),0 + f(ind + 1,transaction,dp,prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(4,-1));

        return f(0,0,dp,prices);
        
    }
};