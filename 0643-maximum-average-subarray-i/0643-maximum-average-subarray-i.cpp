class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low = 0;
        int high = k-1;
        double sum =0;
        int n = nums.size();

        for(int i = low; i <= high; i++){
            sum += nums[i];
            

        }
        
        double res = sum/k;

        while(high < n){
            
            low++;
            high++;

            if(high == n) break;

           

            sum = sum - nums[low-1];
            sum = sum + nums[high];

            res = max(res,sum/k);



        }
        return res;
        
    }
};