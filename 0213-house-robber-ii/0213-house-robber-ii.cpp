class Solution {
public:

    int maxsum(int i, vector<int>& temp, vector<int>& dp) {
        if(i == 0)
            return temp[0];

        if(i < 0)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int pick = temp[i] + maxsum(i-2, temp, dp);

        int notpick = maxsum(i-1, temp, dp);

        return dp[i] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        // Exclude first
        for(int i = 0; i < n; i++) {
            if(i != 0)
                temp1.push_back(nums[i]);
        }

        // Exclude last
        for(int i = 0; i < n; i++) {
            if(i != n-1)
                temp2.push_back(nums[i]);
        }

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        int ans1 = maxsum(temp1.size()-1, temp1, dp1);
        int ans2 = maxsum(temp2.size()-1, temp2, dp2);

        return max(ans1, ans2);
    }
};