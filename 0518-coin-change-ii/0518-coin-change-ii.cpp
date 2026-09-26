class Solution {
public:
    int countpath(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(ind == 0){
            if(target % nums[0] == 0) return 1;
            else return 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTake = countpath(ind-1,target,nums,dp);

        int take = 0;
        if(nums[ind] <= target){
            take = countpath(ind,target-nums[ind],nums,dp);
        }

        return dp[ind][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return countpath(n-1,amount,coins,dp);
        
    }
};