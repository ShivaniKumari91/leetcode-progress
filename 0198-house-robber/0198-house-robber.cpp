class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev = nums[0];

        for(int i = 1; i< nums.size(); i++){
            int take = nums[i];
            if(i > 0){
                take = nums[i] + prev2;

            }
            int nontake = 0 + prev;

            int curr = max(take,nontake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
        
        
    }
};