class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int mini = INT_MAX;

        for(int i = 0; i<n-1; i++){
            mini = min(mini,prices[i]);
            int profit = prices[i+1] - mini;
            maxi = max(maxi,profit);
        }

        
        return maxi;
        
    }
};