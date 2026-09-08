class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(m,vector<int>(n));
        for(int j = 0;j < n; j++){
            dp[m-1][j] = matrix[m-1][j];
        }

        for(int i = m-2;i >= 0;i--){
            for(int j = 0; j< n; j++){
                int leftdiag = 1e9;
                int rightdiag = 1e9;

                if(j-1 >= 0) leftdiag = matrix[i][j] + dp[i+1][j-1];

                int down = matrix[i][j] + dp[i+1][j]; 

                if(j+1 < n) rightdiag = matrix[i][j] + dp[i+1][j+1];

                dp[i][j] = min({leftdiag,down,rightdiag});

               
            }
        }
        for(int j = 0; j<n; j++){
            ans = min(ans,dp[0][j]);
        }
        return ans;
        
    }
}; 