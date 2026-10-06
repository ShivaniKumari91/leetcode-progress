class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[i] = longest increasing subsequence ending at i
        vector<int> dp(n, 1);

        // cnt[i] = number of LIS of length dp[i] ending at i
        vector<int> cnt(n, 1);

        for(int i = 0; i < n; i++) {

            for(int prev = 0; prev < i; prev++) {

                if(nums[i] > nums[prev] &&
                   dp[prev] + 1 > dp[i]) {

                    dp[i] = dp[prev] + 1;

                    // New longer length found
                    cnt[i] = cnt[prev];
                }

                else if(nums[i] > nums[prev] &&
                        dp[prev] + 1 == dp[i]) {

                    // Same maximum length found again
                    cnt[i] += cnt[prev];
                }
            }
        }

        // Find overall maximum LIS length
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, dp[i]);
        }

        // Add counts of all positions having maximum length
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};