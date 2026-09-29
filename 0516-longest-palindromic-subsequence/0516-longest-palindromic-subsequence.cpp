class Solution {
public:

    int lcs(int i, int j, string &s, string &t,
            vector<vector<int>> &dp) {

        // Base case
        if(i < 0 || j < 0)
            return 0;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if(s[i] == t[j]) {
            return dp[i][j] = 1 + lcs(i-1, j-1, s, t, dp);
        }

        // Characters don't match
        return dp[i][j] = max(
            lcs(i-1, j, s, t, dp),
            lcs(i, j-1, s, t, dp)
        );
    }

    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return lcs(n-1, m-1, s, t, dp);
    }
};