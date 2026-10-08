class Solution {
public:

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        // Add 1 at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[i][j] = maximum coins from balloons i to j
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // i goes from n to 1
        for(int i = n; i >= 1; i--) {

            // j goes from i to n
            for(int j = i; j <= n; j++) {

                int maxi = 0;

                // Try every balloon as the LAST balloon
                for(int ind = i; ind <= j; ind++) {

                    int coins =
                        nums[i - 1] * nums[ind] * nums[j + 1]
                        + dp[i][ind - 1]
                        + dp[ind + 1][j];

                    maxi = max(maxi, coins);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};