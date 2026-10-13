class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a = 0;
        int b = 1;
        int c = 1;


        while(true){
            int sum = a + b + c;

            if(sum == n) return true;

            if(sum > n) return false;

            a = b;
            b = c;
            c = a + b;
        }
        
    }
};