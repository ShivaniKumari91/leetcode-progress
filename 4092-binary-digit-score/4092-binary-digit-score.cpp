class Solution {
public:
    // Function to count the number of set bits (1s) in binary representation
    int f(int n) {
        int cnt = 0;

        // Keep checking bits until n becomes 1 or 0
        while (n > 1) {

            // If the last bit is 1, increment count
            if (n % 2 == 1) {
                cnt++;
            }

            // Right shift by 1 to remove the last bit
            n >>= 1;
        }

        // If n becomes 1, count this last set bit
        if (n == 1) {
            cnt++;
        }

        return cnt;
    }

    int calculateScore(int a, int b) {

        // Count set bits in a and b
        int s1 = f(a);
        int s2 = f(b);

        // If s1 >= s2, score = s1 * s2
        if (s1 >= s2) {
            return s1 * s2;
        }
        // Otherwise, score = s2 / s1 (integer division)
        else {
            return s2 / s1;
        }
    }
};