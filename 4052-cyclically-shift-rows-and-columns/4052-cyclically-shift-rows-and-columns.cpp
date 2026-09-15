class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
         vector<vector<int>> ans(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                // Step 1: shift row i to the left
                int newCol = (j - rowShift[i] + n) % n;

                // Step 2: shift this column upward
                int newRow = (i - colShift[newCol] + n) % n;

                // Put element at its final position
                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
        
    }
};