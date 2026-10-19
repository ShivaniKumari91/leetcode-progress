class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        // Total subsets = 2^n
        int subset = 1 << n;

        vector<vector<int>> ans;

        // Each number represents one subset using its bits
        for(int num = 0; num < subset; num++) {

            vector<int> ds;

            // Check each bit to decide which element to include
            for(int i = 0; i < n; i++) {

                // If ith bit is set, include nums[i]
                if(num & (1 << i)) {
                    ds.push_back(nums[i]);
                }
            }

            // Store the current subset
            ans.push_back(ds);
        }

        return ans;
    }
};