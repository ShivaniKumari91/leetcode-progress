class Solution {
public:
    int minBitFlips(int start, int goal) {

        int ans = 0;

        // XOR gives 1 where bits are different
        int x = start ^ goal;

        while(x != 0) {

            // If the last bit is 1, increment count
            ans += x & 1;

            // Right-shift to check the next bit
            x >>= 1;
        }

        return ans;
    }
};