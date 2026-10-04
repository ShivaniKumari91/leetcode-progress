class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[ind][prev + 1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // ind goes from n-1 to 0
        for(int ind = n - 1; ind >= 0; ind--) {

            // prev can be -1 to n-1
            for(int prev = ind - 1; prev >= -1; prev--) {

                // Don't take
                int notTake = dp[ind + 1][prev + 1];

                // Take
                int take = 0;

                if(prev == -1 || nums[ind] > nums[prev])
                    take = 1 + dp[ind + 1][ind + 1];

                dp[ind][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};