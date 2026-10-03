class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
                int n = prices.size();

        vector<int> ahead(2*k+1,0);
        vector<int> cur(2*k+1,0);

        for(int trans = 0; trans <= 2*k; trans++){
            ahead[trans] = 0;
        }

       

        for(int ind = n-1; ind>=0; ind--){
            cur[(2*k)] = 0;
            for(int transaction = (2*k)-1; transaction >= 0;transaction--){
                if(transaction % 2 == 0){
                    cur[transaction] = max(-prices[ind] + ahead[transaction + 1],
                                                0 + ahead[transaction]);
                }
                else{
                    cur[transaction] = max(prices[ind] + ahead[transaction + 1],
                                                0 + ahead[transaction]);
                }
            }
            ahead = cur;
        }

        return ahead[0];
        
    }
};