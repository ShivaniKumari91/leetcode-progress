class Solution {
public:

    bool f(int i, int j, string &s, string &p,
           vector<vector<int>> &dp) {

        // Both exhausted
        if(i < 0 && j < 0)
            return true;

        // Pattern exhausted, string still left
        if(i < 0 && j >= 0)
            return false;

        // String exhausted
        if(j < 0 && i >= 0) {
            for(int k = 0; k <= i; k++) {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // Same character or '?'
        if(p[i] == s[j] || p[i] == '?') {
            return dp[i][j] =
                f(i-1, j-1, s, p, dp);
        }

        // '*'
        if(p[i] == '*') {

            // '*' takes zero characters
            // OR
            // '*' takes current character

            return dp[i][j] =
                f(i-1, j, s, p, dp) ||
                f(i, j-1, s, p, dp);
        }

        return dp[i][j] = false;
    }


    bool isMatch(string s, string p) {

        int n = p.size();
        int m = s.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n-1, m-1, s, p, dp);
    }
};