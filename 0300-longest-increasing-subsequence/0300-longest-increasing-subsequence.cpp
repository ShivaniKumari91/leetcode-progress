class Solution {
public:
     int f(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {

        // Base case
        if(ind == nums.size())
            return 0;

        // Already calculated
        if(dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];

        // Option 1: Don't take nums[ind]
        int notTake = f(ind + 1, prev, nums, dp);

        // Option 2: Take nums[ind]
        int take = 0;

        if(prev == -1 || nums[ind] > nums[prev])
            take = 1 + f(ind + 1, ind, nums, dp);

        return dp[ind][prev + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        // prev can be -1, so we use prev + 1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(0, -1, nums, dp);
    }
};