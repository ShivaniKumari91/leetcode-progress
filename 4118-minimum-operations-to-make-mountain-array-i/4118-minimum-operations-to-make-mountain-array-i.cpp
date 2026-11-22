class Solution {
    const int mx = 2000;
    const int inf = 1e9;

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) return -1;

        vector<vector<int>> dp1(n, vector<int>(mx, inf));

        // DP1: Strictly increasing (Left to Right)
        for (int j = 1; j < mx; j++) {
            dp1[0][j] = abs(nums[0] - j);
        }

        for (int i = 1; i < n; i++) {
            int mn = inf;

            for (int j = 1; j < mx; j++) {
                dp1[i][j] = abs(nums[i] - j) + mn;
                mn = min(mn, dp1[i-1][j]);
            }
        }

        vector<vector<int>> dp2(n, vector<int>(mx, inf));

        // DP2: Strictly decreasing (Right to Left)
        for (int j = 1; j < mx; j++) {
            dp2[n-1][j] = abs(nums[n-1] - j);
        }

        for (int i = n-2; i >= 0; i--) {
            int mn = inf;

            for (int j = 1; j < mx; j++) {
                dp2[i][j] = abs(nums[i] - j) + mn;
                mn = min(mn, dp2[i+1][j]);
            }
        }

        // Combine both DP arrays by choosing every possible peak
        int ans = inf;

        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < mx; j++) {
                ans = min(ans,
                    dp1[i][j] + dp2[i][j] - abs(nums[i] - j));
            }
        }

        return ans;
    }
};