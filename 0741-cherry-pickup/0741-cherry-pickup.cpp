class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> prev(
            n + 1,
            vector<int>(n + 1, -1e8)
        );

        for(int r1 = n - 1; r1 >= 0; r1--) {

            vector<vector<int>> cur(
                n + 1,
                vector<int>(n + 1, -1e8)
            );

            for(int c1 = n - 1; c1 >= 0; c1--) {

                for(int r2 = n - 1; r2 >= 0; r2--) {

                    int c2 = r1 + c1 - r2;

                    // Invalid column
                    if(c2 < 0 || c2 >= n)
                        continue;

                    // Blocked cell
                    if(grid[r1][c1] == -1 ||
                       grid[r2][c2] == -1)
                        continue;

                    // Destination
                    if(r1 == n - 1 && c1 == n - 1) {

                        if(r2 == n - 1 && c2 == n - 1)
                            cur[c1][r2] = grid[r1][c1];

                        continue;
                    }

                    int cherry;

                    // Both robots on same cell
                    if(r1 == r2 && c1 == c2)
                        cherry = grid[r1][c1];

                    else
                        cherry = grid[r1][c1] +
                                 grid[r2][c2];


                    // Four choices

                    // R R
                    int rr = cur[c1 + 1][r2];

                    // R D
                    int rd = cur[c1 + 1][r2 + 1];

                    // D R
                    int dr = prev[c1][r2];

                    // D D
                    int dd = prev[c1][r2 + 1];


                    cur[c1][r2] =
                        cherry + max({rr, rd, dr, dd});
                }
            }

            prev = cur;
        }

        return max(0, prev[0][0]);
    }
};