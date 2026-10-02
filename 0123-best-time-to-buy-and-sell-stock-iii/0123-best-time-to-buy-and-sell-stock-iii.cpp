class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> after(5,0);
        for(int trans = 0; trans <= 4; trans++){
            after[trans] = 0;
        }
        vector<int> cur(5,0);

       

      

        for(int ind = n-1; ind>=0; ind--){
            cur[4] = 0;
            for(int transaction = 3; transaction >= 0;transaction--){
                if(transaction % 2 == 0){
                    cur[transaction] = max(-prices[ind] + after[transaction + 1],
                                                0 + after[transaction]);
                }
                else{
                    cur[transaction] = max(prices[ind] + after[transaction + 1],
                                                0 + after[transaction]);
                }
            }
            after = cur;
        }

        return after[0];

       
        
    }
};