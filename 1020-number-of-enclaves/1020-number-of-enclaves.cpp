class Solution {
public:
    void dfs(int row,int col, vector<vector<int>> &visited,int delrow[],int delcol[],vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();

        visited[row][col] = 1;

        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                dfs(nrow,ncol,visited,delrow,delcol,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m  = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int delrow[] = {-1,+1,0,0};
        int delcol[] = {0,0,-1,1};

        for(int j = 0; j<n; j++){
            if(grid[0][j]==1 && !visited[0][j]){
                dfs(0,j,visited,delrow,delcol,grid);
            }
        }

        for(int j = 0; j<n; j++){
            if(grid[m-1][j]==1 && !visited[m-1][j]){
                dfs(m-1,j,visited,delrow,delcol,grid);
            }
        }

        for(int i = 0; i<m; i++){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(i,0,visited,delrow,delcol,grid);
            }
        }

        for(int i = 0; i<m; i++){
            if(grid[i][n-1]==1 && !visited[i][n-1]){
                dfs(i,n-1,visited,delrow,delcol,grid);
            }
        }
        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    cnt++;

                }
            }
        }
        return cnt;

    }
};