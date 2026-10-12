
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of columns

        // dp[i][j] = largest square submatrix of all 1s
        // whose bottom-right corner is at (i, j).
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // First column:
        // We cannot form a square larger than 1x1
        // using only the first column.
        // So dp[i][0] = matrix[i][0].
        for(int i = 0; i < n; i++)
            dp[i][0] = matrix[i][0];

        // First row:
        // We cannot form a square larger than 1x1
        // using only the first row.
        // So dp[0][j] = matrix[0][j].
        for(int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];

        // Start from (1, 1), because the first row
        // and first column are already initialized.
        for(int i = 1; i < n; i++){

            for(int j = 1; j < m; j++){

                // If the current cell is 0,
                // no square of 1s can end here.
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;

                else{
                    // Check the three neighboring cells:
                    // Top, left and top-left diagonal.
                    // The minimum decides how much the square
                    // can be extended from the current cell.
                    dp[i][j] = 1 + min({
                        dp[i-1][j],     // Top
                        dp[i-1][j-1],   // Top-left diagonal
                        dp[i][j-1]      // Left
                    });
                }
            }
        }

        // Every dp[i][j] counts all-1 squares
        // ending at that particular cell.
        // Therefore, add all DP values to get the total.
        int sum = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum += dp[i][j];
            }
        }

        return sum;
    }
};
