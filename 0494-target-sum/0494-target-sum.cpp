class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int totalSum = 0;

        for(int x : nums)
            totalSum += x;

        if(totalSum - target < 0)
            return 0;

        if((totalSum - target) % 2 != 0)
            return 0;

        int required = (totalSum - target) / 2;

        vector<int> prev(required + 1, 0);
        vector<int> cur(required + 1, 0);

        // Base case
        if(nums[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if(nums[0] != 0 && nums[0] <= required)
            prev[nums[0]] = 1;

        for(int ind = 1; ind < n; ind++) {

            // Current row ko reset karo
            fill(cur.begin(), cur.end(), 0);

            for(int sum = 0; sum <= required; sum++) {

                int notTake = prev[sum];

                int take = 0;

                if(nums[ind] <= sum)
                    take = prev[sum - nums[ind]];

                cur[sum] = take + notTake;
            }

            prev = cur;
        }

        return prev[required];
    }
};