class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, 0))
        );

        // Base case: last row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {

                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] =
                        grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        // Move from bottom row to top row
        for (int i = n - 2; i >= 0; i--) {

            for (int j1 = 0; j1 < m; j1++) {

                for (int j2 = 0; j2 < m; j2++) {

                    int maxi = -1e9;

                    // Robot 1: 3 directions
                    for (int d1 = -1; d1 <= 1; d1++) {

                        // Robot 2: 3 directions
                        for (int d2 = -1; d2 <= 1; d2++) {

                            int value;

                            // Current row cherries
                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;

                            // Check boundaries
                            if (nj1 >= 0 && nj1 < m &&
                                nj2 >= 0 && nj2 < m) {

                                value += dp[i + 1][nj1][nj2];

                                maxi = max(maxi, value);
                            }
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        // Initially:
        // Robot 1 = column 0
        // Robot 2 = column m-1

        return dp[0][0][m - 1];
    }
};