class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead2(2,0);
        vector<int> ahead1(2,0);
        vector<int> cur(2,0);
        

        for(int ind = n-1; ind >= 0;ind--){
            cur[1] = max(-prices[ind] + ahead1[0], 0 + ahead1[1]);

            cur[0] = max(prices[ind] + ahead2[1],0 + ahead1[0]);

            ahead2 = ahead1;
            ahead1 = cur;
        }
        return cur[1];

        
        
    }
};