class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int totalSum = 0;

        for(int x : nums)
            totalSum += x;


        // We divide array into S1 and S2
        //
        // S1 - S2 = target
        // S1 + S2 = totalSum
        //
        // Therefore:
        // S2 = (totalSum - target) / 2

        // Required subset sum cannot be negative
        if(totalSum - target < 0)
            return 0;

        // Required sum must be an integer
        if((totalSum - target) % 2 != 0)
            return 0;

        int sum = (totalSum - target) / 2;


        // dp[i][j] =
        // first i+1 elements se sum j
        // banane ke number of ways

        vector<vector<int>> dp(
            n,
            vector<int>(sum + 1, 0)
        );


        // Base case
        //
        // If first element is 0:
        // +0 and -0 -> 2 ways
        if(nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;


        // First element itself can make this sum
        if(nums[0] != 0 && nums[0] <= sum)
            dp[0][nums[0]] = 1;


        // Fill the table
        for(int i = 1; i < n; i++) {

            for(int j = 0; j <= sum; j++) {

                // Don't take nums[i]
                int notTake = dp[i-1][j];

                // Take nums[i]
                int take = 0;

                if(nums[i] <= j)
                    take = dp[i-1][j - nums[i]];

                // Total number of ways
                dp[i][j] = take + notTake;
            }
        }


        // Required sum banane ke total ways
        return dp[n-1][sum];
    }
};