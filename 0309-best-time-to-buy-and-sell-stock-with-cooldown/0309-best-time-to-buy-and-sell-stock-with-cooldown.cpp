class Solution {
public:
    int f(int ind,int buy,vector<vector<int>> &dp,vector<int> &prices){
        if(ind == prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy == 1){
            return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,dp,prices),0 + f(ind+1,1,dp,prices));
        } 
        else if(buy == 0){
            return dp[ind][buy] = max(prices[ind] + f(ind+1,2,dp,prices), 0 + f(ind+1,0,dp,prices));
        }
        else{
            return dp[ind][buy] = f(ind+1,1,dp,prices);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));

        return f(0,1,dp,prices);
        
    }
};