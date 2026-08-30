class Solution {
public:

    long long power(long long x, long long y, long long MOD) {
        long long ans = 1;

        while(y > 0) {

            if(y % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            y = y / 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        const long long MOD = 1e9 + 7;

        for(long long i = 0; i < nums.size(); i++) {

            long long d = nums[i] / 10;
            long long temp = d;

            long long width = nums[i] % 10;

            long long dcnt = 0;

            while(temp > 0) {
                dcnt++;
                temp /= 10;
            }

            long long ylength = dcnt - width;

            long long p = 1;

            for(int j = 0; j < ylength; j++)
                p *= 10;

            long long y = d % p;
            long long x = d / p;

            long long decoded = power(x, y, MOD);

            sum = (sum + decoded) % MOD;
        }

        return sum;
    }
};