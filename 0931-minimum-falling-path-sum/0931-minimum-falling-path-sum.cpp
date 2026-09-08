class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix,
          vector<vector<int>>& dp) {

        int m = matrix.size();
        int n = matrix[0].size();

        // Out of boundary
        if (j < 0 || j > n-1)
            return 1e9;

        // Last row
        if (i == m - 1)
            return matrix[i][j];

        // Already calculated
        if (dp[i][j] != -101)
            return dp[i][j];

        int leftdiag = matrix[i][j] + f(i + 1, j - 1, matrix, dp);
        int down = matrix[i][j] + f(i + 1, j, matrix, dp);
        int rightdiag = matrix[i][j] + f(i + 1, j + 1, matrix, dp);

        return dp[i][j] = min({leftdiag, down, rightdiag});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int ans = INT_MAX;

        vector<vector<int>> dp(m, vector<int>(n, -101));

        // Starting point can be anywhere in first row
        for (int i = 0; i < n; i++) {

            int mini = f(0, i, matrix, dp);

            ans = min(ans, mini);
        }

        return ans;
    }
};