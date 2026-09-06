class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {

        int m = grid.size();       // number of rows
        int n = grid[0].size();    // number of columns


        // ---------------------------------------------------
        // STATE:
        // dist[row][col][direction][turns]
        //
        // Kisi cell par pahunchne ka minimum cost store karenge
        // with:
        // 1. current row
        // 2. current column
        // 3. jis direction se current cell mein aaye
        // 4. ab tak kitne turns hue
        // ---------------------------------------------------

        // Direction:
        // 0 = UP
        // 1 = DOWN
        // 2 = LEFT
        // 3 = RIGHT
        // 4 = NO_DIRECTION (starting cell)

        vector<vector<vector<vector<int>>>> dist(
            m,
            vector<vector<vector<int>>>(
                n,
                vector<vector<int>>(5, vector<int>(k + 1, 1e9))
            )
        );


        // ---------------------------------------------------
        // PRIORITY QUEUE
        //
        // Dijkstra use kar rahe hain.
        //
        // Queue mein 5 cheezein store hongi:
        //
        // {cost, row, col, direction, turns}
        //
        // Priority sabse kam cost wali state ko milegi.
        // ---------------------------------------------------

        priority_queue<
            tuple<int,int,int,int,int>,
            vector<tuple<int,int,int,int,int>>,
            greater<tuple<int,int,int,int,int>>
        > pq;


        // ---------------------------------------------------
        // STARTING STATE
        //
        // Starting cell = (0,0)
        // Starting cost = grid[0][0]
        // Abhi koi direction nahi hai = 4
        // Abhi koi turn nahi hua = 0
        // ---------------------------------------------------

        dist[0][0][4][0] = grid[0][0];

        pq.push({grid[0][0], 0, 0, 4, 0});


        // Direction arrays
        //
        // newDir = 0 → UP
        // newDir = 1 → DOWN
        // newDir = 2 → LEFT
        // newDir = 3 → RIGHT

        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};


        // ---------------------------------------------------
        // DIJKSTRA
        // ---------------------------------------------------

        while(!pq.empty()) {


            // Queue se minimum cost wali state nikalo

            auto [cost, row, col, dir, turn] = pq.top();
            pq.pop();


            // ---------------------------------------------------
            // STALE STATE CHECK
            //
            // Ho sakta hai same state pehle kisi expensive cost
            // ke saath queue mein push hui ho aur baad mein
            // cheaper cost mil gayi ho.
            //
            // Agar queue wali cost current best dist ke equal nahi
            // hai, to ye purani/stale entry hai.
            // ---------------------------------------------------

            if(cost != dist[row][col][dir][turn])
                continue;


            // ---------------------------------------------------
            // DESTINATION
            //
            // Agar last cell par pahunch gaye,
            // Dijkstra ki wajah se ye minimum cost hoga.
            // ---------------------------------------------------

            if(row == m-1 && col == n-1)
                return cost;


            // ---------------------------------------------------
            // CURRENT CELL SE 4 DIRECTIONS TRY KARO
            // ---------------------------------------------------

            for(int newDir = 0; newDir < 4; newDir++) {


                // Next cell calculate karo

                int nrow = row + di[newDir];
                int ncol = col + dj[newDir];


                // ---------------------------------------------------
                // CHECK:
                // Next cell grid ke andar hai ya nahi
                // ---------------------------------------------------

                if(nrow < 0 || nrow >= m ||
                   ncol < 0 || ncol >= n) {
                    continue;
                }


                // ---------------------------------------------------
                // Initially turns same rahenge.
                // ---------------------------------------------------

                int newTurns = turn;


                // ---------------------------------------------------
                // TURN CHECK
                //
                // Agar direction change hui,
                // to ek turn increase hoga.
                //
                // dir == 4 means first move.
                // First move ko turn nahi count karna.
                // ---------------------------------------------------

                if(dir != 4 && newDir != dir) {
                    newTurns++;
                }


                // ---------------------------------------------------
                // Agar allowed k se zyada turns ho gaye,
                // ye path reject.
                // ---------------------------------------------------

                if(newTurns > k)
                    continue;


                // ---------------------------------------------------
                // NEW COST
                //
                // Current cost + next cell ka cost
                // ---------------------------------------------------

                int newCost = cost + grid[nrow][ncol];


                // ---------------------------------------------------
                // RELAXATION
                //
                // Agar next state ka new cost uske current
                // minimum cost se chhota hai,
                // to update karo.
                //
                // IMPORTANT:
                // State sirf (row,col) nahi hai.
                //
                // State =
                // (row, col, direction, turns)
                // ---------------------------------------------------

                if(newCost < dist[nrow][ncol][newDir][newTurns]) {

                    // Minimum cost update

                    dist[nrow][ncol][newDir][newTurns] = newCost;


                    // ---------------------------------------------------
                    // Queue mein NEW STATE push
                    //
                    // {cost, row, col, direction, turns}
                    //
                    // newDir ab next iteration mein previous
                    // direction ban jayega.
                    // ---------------------------------------------------

                    pq.push({
                        newCost,
                        nrow,
                        ncol,
                        newDir,
                        newTurns
                    });
                }
            }
        }


        // Destination unreachable
        return -1;
    }
};