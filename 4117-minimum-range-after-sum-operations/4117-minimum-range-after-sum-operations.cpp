class Solution {
public:
    int minRange(int a, int b, int c) {
        int totSum = a + b + c;
        int range = max({a,b,c}) - min({a,b,c});
        int ans = INT_MAX;
        ans = min(ans,range);

        int valA = totSum - a;
        range = valA - min(b,c);
        ans = min(ans,range);

        int valB = totSum - b;
        range = valB - min(a,c);
        ans = min(ans,range);

        int valC = totSum - c;
        range = valC - min(a,b);
        ans = min(range,ans);

        return ans;



        
    }
};