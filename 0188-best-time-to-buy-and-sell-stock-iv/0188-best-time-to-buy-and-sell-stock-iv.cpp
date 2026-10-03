class Solution {
public:
    int f(int ind, int transaction,int k,vector<vector<int>> &dp,vector<int> &prices){
        if(ind == prices.size() || transaction == 2*k) return 0;

        if(dp[ind][transaction] != -1) return dp[ind][transaction];

        if(transaction % 2 == 0){
            return dp[ind][transaction] = max(-prices[ind] + f(ind + 1,transaction + 1,k,dp,prices),0 + f(ind + 1,transaction,k,dp,prices));
        }

        else{
            return dp[ind][transaction] = max(prices[ind] + f(ind + 1,transaction + 1,k,dp,prices),0 + f(ind + 1,transaction,k,dp,prices));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2*(k+1),-1));
        
    
       return f(0,0,k,dp,prices);
    }
};