class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        // Out of bounds
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;

        // Last row
        if (i == n - 1) {
            if (j1 == j2)
                return grid[i][j1];

            return grid[i][j1] + grid[i][j2];
        }

        // Already calculated
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = -1e9;

        // 3 choices for Robot 1
        for (int d1 = -1; d1 <= 1; d1++) {

            // 3 choices for Robot 2
            for (int d2 = -1; d2 <= 1; d2++) {

                int value;

                // Both robots on same cell
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += solve(i + 1, j1 + d1, j2 + d2, grid, dp);

                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1))
        );

        return solve(0, 0, m - 1, grid, dp);
    }
};