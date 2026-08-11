class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dist(m, vector<int> (n,0));
        vector<int> drow = {-1,1,0,0};
        vector<int> dcol = {0,0,1,-1};


        

        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i<m; i++){
            for(int j =0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;

            int steps = q.front().second;
            q.pop();
            dist[r][c] = steps;

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n && vis[nrow][ncol]==0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }


        }
        return dist;
        
    }
};