class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k<=1) return 0;




        

        int n = nums.size();
        int low = 0;
        int high = 0;
        long long prod = 1;
        int cnt = 0;

        while(high < n){
            prod = prod * nums[high];

            while(prod >= k){
                prod = prod / nums[low];
                low++;
            }
            cnt = cnt + (high-low+1);
            high ++;
        }
        return cnt;

           
        
    }
};