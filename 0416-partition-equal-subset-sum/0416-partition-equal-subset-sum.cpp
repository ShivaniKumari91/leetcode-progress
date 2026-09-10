class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(int i = 0; i<n; i++){
            totalsum += nums[i];
        }

        if(totalsum % 2 != 0) return false;

        int target = totalsum/2;

        vector<vector<bool>> dp(n,vector<bool>(target+1,false));

        for(int i = 0; i<n; i++){
            dp[i][0] = true;
        }
        if(nums[0] <= target) dp[0][nums[0]] = true;

        for(int ind = 1; ind < n; ind++){
            for(int t = 1; t <= target; t++){
                int notTake = dp[ind-1][t];
                int take = false;

                if(nums[ind] <= t){
                    take = dp[ind-1][t-nums[ind]];
                }

                dp[ind][t] = take || notTake;
            }
        }
        return dp[n-1][target];

        
    }
};