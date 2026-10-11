class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);

        int maxSum = INT_MIN;
        
        int sum;

        for(int i = n-1; i>=0; i--){
            int maxSum = INT_MIN;
            int maxi = INT_MIN;

            for(int j = i; j < i+k && j < arr.size(); j++){
                

                int len = j-i+1;

                maxi = max(maxi,arr[j]);

                sum = maxi * len + dp[j+1];

                maxSum = max(sum,maxSum);

               

            }
            dp[i] = maxSum;
        }
        return dp[0];

        
    }
};