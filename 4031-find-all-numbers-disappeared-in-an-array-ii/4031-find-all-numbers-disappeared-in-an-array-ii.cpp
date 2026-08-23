class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] < lower){
                continue;
            }
            if(nums[i] > upper) break;

            if(lower < nums[i]){
                ans.push_back({lower,nums[i]-1});
            }

            lower = nums[i]+1;
        }
        if(lower <= upper){
            ans.push_back({lower,upper});
        }

        return ans;
        
    }
};