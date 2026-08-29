class Solution {
public:
    int maxsum(vector<int> &nums){
        int bestend = nums[0];
        int i = 0;
        int res = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int v1 = bestend + nums[i];
            int v2 = nums[i];

            bestend = max(v1,v2);

            res = max(res,bestend);
        }
        return res;
    }
    int minsum(vector<int> &nums){

        int bestend = nums[0];
        int i = 0;
        int res = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int v1 = bestend + nums[i];
            int v2 = nums[i];

            bestend = min(v1,v2);

            res = min(res,bestend);
        }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = maxsum(nums);
        int mini = minsum(nums);

        int ans;
        ans = max(abs(maxi),abs(mini));

        return ans;
        
    }
};