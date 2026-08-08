class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int cnt = 0;
        

        for(int i=n-1; i>= 0 ;i-- ){

            if(i == n-1 || nums[i]!=nums[i+1]){
                cnt++;

            }
            if(cnt==3){
                return nums[i];
            }

            
        }
        return nums[n-1];
        
    }
};