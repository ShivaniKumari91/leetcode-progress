
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int aheadBuy = 0;
        int aheadSell = 0;
        int curBuy,curSell;

        for (int ind = n - 1; ind >= 0; ind--) {

            curBuy = max(
                -prices[ind] + aheadSell,
                aheadBuy
            );

            curSell = max(
                prices[ind] + aheadBuy,
                aheadSell
            );

            aheadBuy = curBuy;
            aheadSell = curSell;
        }

        return aheadBuy;
    }
};

