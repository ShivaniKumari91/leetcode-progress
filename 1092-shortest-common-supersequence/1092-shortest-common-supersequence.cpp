class Solution {
public:

    int lcs(int i, int j, string &s1, string &s2,
            vector<vector<int>> &dp) {

        // Base case
        if(i == 0 || j == 0)
            return 0;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // Same character
        if(s1[i-1] == s2[j-1]) {
            return dp[i][j] =
                1 + lcs(i-1, j-1, s1, s2, dp);
        }

        // Different character
        return dp[i][j] =
            max(lcs(i-1, j, s1, s2, dp),
                lcs(i, j-1, s1, s2, dp));
    }


    string shortestCommonSupersequence(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1,
            vector<int>(m+1, -1));

        // First find LCS using memoization
        lcs(n, m, s1, s2, dp);

        // Now reconstruct SCS
        int i = n;
        int j = m;

        string ans = "";

        while(i > 0 && j > 0) {

            // Same character -> take once
            if(s1[i-1] == s2[j-1]) {

                ans += s1[i-1];
                i--;
                j--;
            }

            // Take from s1
            else if(dp[i-1][j] > dp[i][j-1]) {

                ans += s1[i-1];
                i--;
            }

            // Take from s2
            else {

                ans += s2[j-1];
                j--;
            }
        }

        // Remaining characters
        while(i > 0) {
            ans += s1[i-1];
            i--;
        }

        while(j > 0) {
            ans += s2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};