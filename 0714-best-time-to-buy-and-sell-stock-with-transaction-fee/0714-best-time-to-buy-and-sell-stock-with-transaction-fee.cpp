class Solution {
public:
    int f(int ind,int buy,vector<vector<int>> &dp,vector<int> &prices,int fee){

        if(ind == prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy == 1){
            return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,dp,prices,fee), 0 + f(ind+1,1,dp,prices,fee));
        }

        else{
            return dp[ind][buy] = max((prices[ind] - fee) + f(ind+1,1,dp,prices,fee) , 0 + f(ind+1,0,dp,prices,fee));
        }

    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(0,1,dp,prices,fee);
        
    }
};