class Solution {
public:

    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {

        // No balloon left
        if(i > j) {
            return 0;
        }

        // Already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int maxi = 0;

        // Try every balloon as the LAST balloon to burst
        for(int ind = i; ind <= j; ind++) {

            int coins =
                nums[i - 1] * nums[ind] * nums[j + 1]
                + f(i, ind - 1, nums, dp)
                + f(ind + 1, j, nums, dp);

            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        // Add 1 at both boundaries
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return f(1, n, nums, dp);
    }
};