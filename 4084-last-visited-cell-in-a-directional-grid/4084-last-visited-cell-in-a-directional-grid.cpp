class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int row = 0;
        int col = 0;

        // Starting cell is already visited
        visited[0][0] = true;

        while(true) {

            if(grid[row][col] == 'R') {
                int nextRow = row;
                int nextCol = col + 1;

                if(nextCol >= m || visited[nextRow][nextCol] == true) {
                    break;
                }

                col++;

                // Mark the new cell as visited
                visited[row][col] = true;
            }
            else if(grid[row][col] == 'D') {
                int nextRow = row + 1;
                int nextCol = col;

                if(nextRow >= n || visited[nextRow][nextCol] == true) {
                    break;
                }

                row++;

                // Mark the new cell as visited
                visited[row][col] = true;
            }
            else if(grid[row][col] == 'U') {
                int nextRow = row - 1;
                int nextCol = col;

                if(nextRow < 0 || visited[nextRow][nextCol] == true) {
                    break;
                }

                row--;

                // Mark the new cell as visited
                visited[row][col] = true;
            }
            else if(grid[row][col] == 'L') {
                int nextRow = row;
                int nextCol = col - 1;

                if(nextCol < 0 || visited[nextRow][nextCol] == true) {
                    break;
                }

                col--;

                // Mark the new cell as visited
                visited[row][col] = true;
            }
        }

        return {row, col};
    }
};