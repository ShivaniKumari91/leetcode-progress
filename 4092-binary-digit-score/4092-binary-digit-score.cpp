class Solution {
public:
    int f(int n){
        int cnt = 0;
        while(n > 1){
            if(n % 2 == 1){
                cnt = cnt+1;
            }
            n = n >> 1;
        }
        if(n == 1) cnt += 1;
        return cnt;
    }
    int calculateScore(int a, int b) {
        int s1 = f(a);
        int s2 = f(b);

        if(s1 >= s2){
            return s1 * s2;
        }
        else{
            return s2 / s1;
        }
        
    }
};