class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        vector<vector<int>> ans(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                // STEP 1: Row i ko LEFT shift karna hai.
                // Left shift => column decrease hoga.
                // Isliye: j - rowShift[i]
                //
                // +n => negative value avoid karne ke liye
                // %n => answer ko 0 se n-1 ke range me lane ke liye

                int newCol = (j - rowShift[i] + n) % n;


                // STEP 2: Ab element newCol par pahunch gaya.
                // Isliye column shift ke liye
                // colShift[newCol] use karenge,
                // NOT colShift[j].
                //
                // Up shift => row decrease hoga.

                int newRow = (i - colShift[newCol] + n) % n;


                // Element ki final position
                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
        
    }
};