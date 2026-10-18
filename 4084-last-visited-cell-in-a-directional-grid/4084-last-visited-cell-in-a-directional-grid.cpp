class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int row = 0;
        int col = 0;

        visited[0][0] = true;

        while(true) {

            if(grid[row][col] == 'R') {
                if(col + 1 >= m || visited[row][col + 1] == true)
                    break;

                col++;
                visited[row][col] = true;
            }
            else if(grid[row][col] == 'D') {
                if(row + 1 >= n || visited[row + 1][col] == true)
                    break;

                row++;
                visited[row][col] = true;
            }
            else if(grid[row][col] == 'U') {
                if(row - 1 < 0 || visited[row - 1][col] == true)
                    break;

                row--;
                visited[row][col] = true;
            }
            else if(grid[row][col] == 'L') {
                if(col - 1 < 0 || visited[row][col - 1] == true)
                    break;

                col--;
                visited[row][col] = true;
            }
        }

        return {row, col};
    }
};