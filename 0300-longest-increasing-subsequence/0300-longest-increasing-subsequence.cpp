class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> next(n + 1, 0);
        vector<int> cur(n + 1, 0);

        for(int ind = n - 1; ind >= 0; ind--) {

            for(int prev = ind - 1; prev >= -1; prev--) {

                // Don't take nums[ind]
                int notTake = next[prev + 1];

                // Take nums[ind]
                int take = 0;

                if(prev == -1 || nums[ind] > nums[prev])
                    take = 1 + next[ind + 1];

                cur[prev + 1] = max(take, notTake);
            }

            // Current row becomes next row
            next = cur;
        }

        return next[0];
    }
};