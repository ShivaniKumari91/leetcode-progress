class Solution {
public:
    int f(int i,int k,vector<int> &arr,vector<int> &dp){
        if(i == arr.size()) return 0;

        if(dp[i] != -1) return dp[i];
        int maxSum = INT_MIN;
        int maxi = INT_MIN;
        int sum;


        for(int j = i; j < i+k && j < arr.size(); j++){
            maxi = max(maxi,arr[j]);
            int len = j-i+1;

            sum = maxi * len + f(j+1,k,arr,dp);

            maxSum = max(sum,maxSum);
            
        }
        return dp[i] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,k,arr,dp);

        
    }
};