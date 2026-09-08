class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MAX;
        vector<int> prev(n);
        for(int j = 0;j < n; j++){
            prev[j] = matrix[m-1][j];
        }

        for(int i = m-2;i >= 0;i--){
            vector<int> temp(n);
            for(int j = 0; j< n; j++){
                int leftdiag = 1e9;
                int rightdiag = 1e9;

                if(j-1 >= 0) leftdiag = matrix[i][j] + prev[j-1];

                int down = matrix[i][j] + prev[j]; 

                if(j+1 < n) rightdiag = matrix[i][j] + prev[j+1];

                temp[j] = min({leftdiag,down,rightdiag});

               
            }
            prev = temp;
        }

        for(int j = 0; j<n; j++){
            ans = min(ans,prev[j]);
        }
        return ans;
        
    }
}; 