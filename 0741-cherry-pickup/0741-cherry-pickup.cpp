class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        const int NEG = -1e8;

        // dp[r1][c1][r2]
        // Robot 1 -> (r1, c1)
        // Robot 2 -> (r2, c2)
        //
        // c2 is not stored because:
        // r1 + c1 = r2 + c2
        //
        // Therefore:
        // c2 = r1 + c1 - r2

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(n + 1,
                vector<int>(n + 1, NEG))
        );

        // Base case:
        // Both robots reach destination
        dp[n-1][n-1][n-1] = grid[n-1][n-1];


        // We are moving BACKWARDS
        //
        // Why?
        // In recursion current state depends on:
        //
        // (r1, c1+1, r2)
        // (r1, c1+1, r2+1)
        // (r1+1, c1, r2)
        // (r1+1, c1, r2+1)
        //
        // So these states must already be calculated.

        for(int r1 = n-1; r1 >= 0; r1--) {

            for(int c1 = n-1; c1 >= 0; c1--) {

                for(int r2 = n-1; r2 >= 0; r2--) {

                    // Calculate c2
                    int c2 = r1 + c1 - r2;

                    // c2 invalid
                    if(c2 < 0 || c2 >= n)
                        continue;

                    // If any robot is on blocked cell
                    if(grid[r1][c1] == -1 ||
                       grid[r2][c2] == -1)
                        continue;

                    // Destination already initialized
                    if(r1 == n-1 && c1 == n-1)
                        continue;


                    // Calculate cherries collected
                    int cherry;

                    // Both robots are on SAME cell
                    // Count its cherry only once
                    if(r1 == r2 && c1 == c2)
                        cherry = grid[r1][c1];

                    // Different cells
                    else
                        cherry = grid[r1][c1] +
                                 grid[r2][c2];


                    // Four possible movements
                    //
                    // Robot 1 = Right
                    // Robot 2 = Right
                    int rr = dp[r1][c1+1][r2];

                    // Robot 1 = Right
                    // Robot 2 = Down
                    int rd = dp[r1][c1+1][r2+1];

                    // Robot 1 = Down
                    // Robot 2 = Right
                    int dr = dp[r1+1][c1][r2];

                    // Robot 1 = Down
                    // Robot 2 = Down
                    int dd = dp[r1+1][c1][r2+1];


                    // Current cherries +
                    // best of four possibilities
                    dp[r1][c1][r2] =
                        cherry + max({rr, rd, dr, dd});
                }
            }
        }

        // Starting position:
        // Robot 1 = (0,0)
        // Robot 2 = (0,0)
        return max(0, dp[0][0][0]);
    }
};