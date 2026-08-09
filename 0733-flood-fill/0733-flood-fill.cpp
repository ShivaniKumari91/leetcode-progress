class Solution {
public:
    void bfs (int row,int col, vector<vector<int>> &image,int color,vector<int> &drow,vector<int> &dcol){
        int n = image.size();
        int m = image[0].size();
        int originalColor = image[row][col];

        if (originalColor == color) return;
        queue<pair<int,int>> q;

        q.push({row,col});
        
        image[row][col] = color;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){

                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == originalColor){

                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
              
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        vector <int> drow = {-1,1,0,0};
        vector <int> dcol = {0,0,-1,1};


        bfs(sr,sc,image,color,drow,dcol);
        return image;
    }
};