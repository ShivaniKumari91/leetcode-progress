class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {

        if((source[0] + source[1]) % 2 !=
           (target[0] + target[1]) % 2) {
            return -1;
        }

        if(source == target)
            return 0;

        queue<pair<pair<int,int>, int>> q;

        vector<vector<int>> vis(9, vector<int>(9, 0));

        q.push({{source[0], source[1]}, 0});
        vis[source[0]][source[1]] = 1;

        int dr[] = {1, 1, -1, -1};
        int dc[] = {-1, 1, -1, 1};

        while(!q.empty()) {

            int sr = q.front().first.first;
            int sc = q.front().first.second;
            int steps = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = sr + dr[i];
                int ncol = sc + dc[i];

                // Keep moving in the same diagonal direction
                while(nrow >= 1 && nrow <= 8 &&
                      ncol >= 1 && ncol <= 8) {

                    if(!vis[nrow][ncol]) {

                        if(nrow == target[0] &&
                           ncol == target[1]) {
                            return steps + 1;
                        }

                        vis[nrow][ncol] = 1;

                        q.push({
                            {nrow, ncol},
                            steps + 1
                        });
                    }

                    nrow += dr[i];
                    ncol += dc[i];
                }
            }
        }

        return -1;
    }
};