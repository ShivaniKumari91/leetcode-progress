
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        // Determine sign
        bool sign = true;

        if (dividend >= 0 && divisor < 0) sign = false;
        if (dividend < 0 && divisor > 0) sign = false;

        // Convert to long long before taking absolute value
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long ans = 0;

        while (n >= d) {
            int cnt = 0;

            while (n >= (d << (cnt + 1))) {
                cnt++;
            }

            ans += (1LL << cnt);
            n -= (d << cnt);
        }

        // Handle overflow
        if (ans >= (1LL << 31) && sign == true)
            return INT_MAX;

        if (ans >= (1LL << 31) && sign == false)
            return INT_MIN;

        return sign ? ans : -ans;
    }
};
