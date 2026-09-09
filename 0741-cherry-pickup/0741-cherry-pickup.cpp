class Solution {
public:

    // f() = maximum cherries from current positions
    // Person 1 -> (r1, c1)
    // Person 2 -> (r2, c2)
    //
    // c2 is not stored because:
    // r1 + c1 = r2 + c2
    // Therefore:
    // c2 = r1 + c1 - r2

    int f(int r1, int c1, int r2,
          vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {

        int n = grid.size();

        // Calculate Person 2's column
        int c2 = r1 + c1 - r2;


        // If any position is outside the grid
        // c2 can also become negative
        // -1e9 = invalid/impossible path
        if (r1 >= n || c1 >= n ||
            r2 >= n || c2 >= n || c2 < 0)
            return -1e9;


        // If any person reaches an obstacle
        // (-1 means blocked cell)
        if (grid[r1][c1] == -1 ||
            grid[r2][c2] == -1)
            return -1e9;


        // Destination reached
        //
        // Both persons move exactly 1 step
        // in every recursive call.
        // So if Person 1 reaches destination,
        // Person 2 also reaches destination.
        if (r1 == n-1 && c1 == n-1)
            return grid[r1][c1];


        // If this state is already calculated,
        // return stored answer.
        // This is the Memoization part of DP.
        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];


        // Calculate cherries at current positions
        int cherries = 0;

        // Both persons are on the same cell
        // Count that cherry only ONCE.
        if (r1 == r2 && c1 == c2)
            cherries = grid[r1][c1];

        // Persons are on different cells
        // Count both cherries.
        else
            cherries = grid[r1][c1] + grid[r2][c2];


        // Four possible simultaneous moves:

        // RR -> Person 1 Right, Person 2 Right
        int rr = f(r1, c1+1, r2, grid, dp);

        // RD -> Person 1 Right, Person 2 Down
        int rd = f(r1, c1+1, r2+1, grid, dp);

        // DR -> Person 1 Down, Person 2 Right
        int dr = f(r1+1, c1, r2, grid, dp);

        // DD -> Person 1 Down, Person 2 Down
        int dd = f(r1+1, c1, r2+1, grid, dp);


        // Choose the path giving maximum cherries
        //
        // Current cherries
        //        +
        // Best future path
        return dp[r1][c1][r2] =
            cherries + max({rr, rd, dr, dd});
    }


    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();


        // 3D DP:
        // dp[r1][c1][r2]
        //
        // c2 is calculated when needed:
        // c2 = r1 + c1 - r2
        //
        // -1 means state is not calculated yet.

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n, -1)
            )
        );


        // Both persons start from (0,0)
        int ans = f(0, 0, 0, grid, dp);


        // If no valid path exists,
        // ans can be -1e9.
        // Cherries cannot be negative,
        // so return at least 0.
        return max(0, ans);
    }
};

//🧠 Super-short revision

//State       → f(r1,c1,r2)
//c2          → r1+c1-r2
//Invalid     → -1e9
//Same cell   → cherry once
//Different   → both cherries
//Moves       → RR, RD, DR, DD
//Choose      → max(4 moves)
//DP          → store state
//Final       → max(0, ans)