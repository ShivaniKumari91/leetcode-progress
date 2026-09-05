class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        // {cost, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dr[] = {0, 1};
        int dc[] = {1, 0};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(cost > dist[r][c])
                continue;

            for(int k = 0; k < 2; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < m && nc < n) {
                    int newCost = cost + grid[nr][nc];

                    if(newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr, nc}});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};