class Solution {
public:
    int largestInteger(int n, int s) {
        if(s > 9*n) return -1;
        int ans = 0;

        while(n){
            int dig = min (9,s);
            ans  = ans * 10 + dig;
            s = s - dig;
            n--;
        }
        return ans;
        
    }
};