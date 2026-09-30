class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {

        int sr = source[0] - 1;
        int sc = source[1] - 1;

        int tr = target[0] - 1;
        int tc = target[1] - 1;

        if(sr == tr && sc == tc) return 0;

        queue<tuple<int, int, int>> q;

        q.push({sr, sc, 0});

        bool vis[8][8] = {};

        vis[sr][sc] = true;

        // 8 directions
        int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

        while (!q.empty()) {

            auto [r, c, steps] = q.front();
            q.pop();

            // Try all 8 directions
            for (int d = 0; d < 8; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Keep moving in same direction
                while (nr >= 0 && nr < 8 &&
                       nc >= 0 && nc < 8) {

                    // Target mil gaya
                    if (nr == tr && nc == tc)
                        return steps + 1;

                    // If not visited, put it in queue
                    if (!vis[nr][nc]) {

                        vis[nr][nc] = true;

                        q.push({nr, nc, steps + 1});
                    }

                    // Move one more square in same direction
                    nr += dr[d];
                    nc += dc[d];
                }
            }
        }

        return 0;
        
    }
};