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

        vector<bool> prev(target+1,false);

        prev[0] = true;

       
        if(nums[0] <= target) prev[nums[0]] = true;

        for(int ind = 1; ind < n; ind++){
            vector<bool> cur(target+1);
            cur[0] = true;
            for(int t = 1; t <= target; t++){
                int notTake = prev[t];
                int take = false;

                if(nums[ind] <= t){
                    take = prev[t-nums[ind]];
                }

                cur[t] = take || notTake;
            }
            prev = cur;
        }
        return prev[target];

        
    }
};