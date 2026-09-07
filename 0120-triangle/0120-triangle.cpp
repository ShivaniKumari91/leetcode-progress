class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> prev(n);
        int i = n-1;
        for(int j = 0; j<=i; j++){
            prev[j] = triangle[i][j];
        }
       

        for(int i = n-2; i>=0; i--){
            vector<int> temp(n);
            for(int j = 0; j<=i; j++){

                int down = triangle[i][j] + prev[j];
                int diag = triangle[i][j] + prev[j+1];

              

                temp[j] = min(down,diag);
            }
            prev = temp;
        }
        return prev[0];
    }
};