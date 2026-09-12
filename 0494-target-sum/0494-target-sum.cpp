class Solution {
public:

    int f(int ind, int target, vector<int>& nums,
          vector<vector<int>>& dp) {

        // Base case
        if(ind == 0) {

            if(target == 0 && nums[0] == 0)
                return 2;

            if(target == 0 || target == nums[0])
                return 1;

            return 0;
        }

        if(dp[ind][target] != -1)
            return dp[ind][target];

        // Not take
        int notTake = f(ind - 1, target, nums, dp);

        // Take
        int take = 0;

        if(nums[ind] <= target)
            take = f(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = take + notTake;
    }


    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int totalSum = 0;

        for(int x : nums)
            totalSum += x;


        // S2 = (TS - target) / 2

        // S2 cannot be negative
        if(totalSum - target < 0)
            return 0;

        // (TS - target) must be even
        if((totalSum - target) % 2 != 0)
            return 0;

        int required = (totalSum - target) / 2;


        // Count subsets having sum = required
        vector<vector<int>> dp(
            n,
            vector<int>(required + 1, -1)
        );

        return f(n - 1, required, nums, dp);
    }
};