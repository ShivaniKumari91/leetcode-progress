class Solution {
public:
    bool isMatch(string s, string p) {

        int n = p.size();
        int m = s.size();

        // dp[i][j] = whether p[0...i-1] matches s[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));

        // Both empty
        dp[0][0] = true;

        // Empty pattern cannot match non-empty string
        for(int j = 1; j <= m; j++) {
            dp[0][j] = false;
        }

        // Empty string can be matched only by all '*'
        for(int i = 1; i <= n; i++) {

            bool flag = true;

            for(int k = 1; k <= i; k++) {
                if(p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }

            dp[i][0] = flag;
        }

        // Fill the table
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                // Same character OR '?'
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?') {

                    dp[i][j] = dp[i - 1][j - 1];
                }

                // '*'
                else if(p[i - 1] == '*') {

                    // '*' matches zero characters
                    // OR
                    // '*' matches current character

                    dp[i][j] =
                        dp[i - 1][j] ||
                        dp[i][j - 1];
                }

                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};