class Solution {
public:

    int lcs(int i, int j, string &s, string &t,
            vector<vector<int>> &dp) {

        // Base case
        if(i == 0 || j == 0)
            return 0;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if(s[i-1] == t[j-1]) {
            return dp[i][j] = 1 + lcs(i-1, j-1, s, t, dp);
        }

        // Characters don't match
        return dp[i][j] = max(
            lcs(i, j-1, s, t, dp),
            lcs(i-1, j, s, t, dp)
        );
    }

    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return lcs(n, m, s, t, dp);
    }

    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};