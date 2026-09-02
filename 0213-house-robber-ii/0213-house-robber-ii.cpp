class Solution {
public:
    int maxsum(vector<int>& temp) {
        int n = temp.size();
        vector<int> dp(n);
        dp[0] = temp[0];

        for(int i = 1; i<n;i++){
            int pick = temp[i];
        

            if(i > 1){

                pick = pick + dp[i-2];
            }
            int notpick = 0 + dp[i-1];

            dp[i] = max(pick,notpick);
        }
        return dp[n-1];

    }   
    int rob(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        int n = nums.size();

        if(n==1) return nums[0];

        for(int i = 0; i<n; i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
        }
        for(int i = 0; i<n; i++){
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        int ans1 = maxsum(temp1);
        int ans2 = maxsum(temp2);
        return max(ans1,ans2);
        
    }
};