class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n));
        int i = n-1;
        for(int j = 0; j<=i; j++){
            dp[i][j] = triangle[i][j];
        }
       

        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<=i; j++){

                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];

              

                dp[i][j] = min(down,diag);
            }
        }
        return dp[0][0];
    }
};