
class Solution {
public:
    bool threeFibonacciSum(int n) {
        // First three Fibonacci terms
        int a = 0, b = 1, c = 1;

        for(;;) {
            // Sum of three consecutive terms
            int sum = a + b + c;

            // Required sum found
            if(sum == n) return true;

            // Sum exceeded n, so no need to continue
            if(sum > n) return false;

            // Calculate the next Fibonacci term
            int next = b + c;

            // Move to the next three consecutive terms
            a = b;
            b = c;
            c = next;
        }
    }
};
