class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        
            int m = grid.size();
        int n = grid[0].size();

        // 0 = UP
        // 1 = DOWN
        // 2 = LEFT
        // 3 = RIGHT
        // 4 = NO_DIRECTION

        vector<vector<vector<vector<int>>>> dist(
            m,
            vector<vector<vector<int>>>(
                n,
                vector<vector<int>>(5, vector<int>(k + 1, 1e9))
            )
        );

        priority_queue<
            tuple<int,int,int,int,int>,
            vector<tuple<int,int,int,int,int>>,
            greater<tuple<int,int,int,int,int>>
        > pq;

        dist[0][0][4][0] = grid[0][0];

        pq.push({grid[0][0],0,0,4,0});

        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};

        while(!pq.empty()){
            auto[cost,row,col,dir,turn] = pq.top();

            pq.pop();

            if(cost!=dist[row][col][dir][turn]) continue;

            if(row == m-1 && col == n-1) return cost;

            for(int newDir = 0; newDir < 4; newDir++){
                int nrow = row + di[newDir];
                int ncol = col + dj[newDir];

                if (nrow < 0 || nrow >= m || ncol < 0 || ncol >= n){
                    continue;
                }
                int newTurns = turn;
               

                if(dir!=4 && newDir!=dir){
                    newTurns++;
                }

                if(newTurns > k) continue;

                int newCost = cost + grid[nrow][ncol];

                if(newCost < dist[nrow][ncol][newDir][newTurns]){
                    dist[nrow][ncol][newDir][newTurns] = newCost;

                    pq.push({newCost,nrow,ncol,newDir,newTurns});
                    
                }



            }
        }
        return -1;
    }
};