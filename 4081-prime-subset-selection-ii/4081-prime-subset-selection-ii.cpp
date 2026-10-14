class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> primes;

        // Generate all primes <= n
        for (int i = 2; i <= n; i++) {
            bool isPrime = true;

            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) primes.push_back(i);
        }

        int m = primes.size();
        const int INF = 1e9;

        // dp[i][sum] = minimum primes needed to make sum
        // using primes from index i onwards
        vector<vector<int>> dp(m + 1, vector<int>(s + 1, INF));

        dp[m][0] = 0;

        for (int i = m - 1; i >= 0; i--) {
            dp[i][0] = 0;

            for (int sum = 1; sum <= s; sum++) {
                // Do not take current prime
                dp[i][sum] = dp[i + 1][sum];

                // Take current prime, if possible
                if (sum >= primes[i] &&
                    dp[i + 1][sum - primes[i]] != INF) {
                    dp[i][sum] = min(
                        dp[i][sum],
                        1 + dp[i + 1][sum - primes[i]]
                    );
                }
            }
        }

        // Find the maximum achievable sum
        int bestSum = s;

        while (bestSum > 0 && dp[0][bestSum] == INF) {
            bestSum--;
        }

        if (bestSum == 0) return {};

        // Reconstruct the lexicographically smallest subset
        vector<int> ans;
        int remainingSum = bestSum;
        int remainingCount = dp[0][bestSum];

        for (int i = 0; i < m && remainingCount > 0; i++) {
            int p = primes[i];

            if (remainingSum >= p &&
                dp[i + 1][remainingSum - p] != INF &&
                dp[i + 1][remainingSum - p] == remainingCount - 1) {

                ans.push_back(p);
                remainingSum -= p;
                remainingCount--;
            }
        }

        return ans;
    }
};