
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int sum = 0;  // Total valid submatrices

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Current cell ko bottom-right corner maanenge
                int width = m;

                // Current row se upar ki rows check karenge
                for(int k = i; k >= 0; k--) {

                    // Agar current column mein 0 mila,
                    // toh is height ka rectangle valid nahi hai
                    if(mat[k][j] == 0)
                        break;

                    int cnt = 0;

                    // Current row mein right se left
                    // consecutive 1s count karenge
                    for(int l = j; l >= 0; l--) {
                        if(mat[k][l] == 0)
                            break;

                        cnt++;
                    }

                    // Har included row mein valid width
                    // minimum consecutive 1s ke barabar hogi
                    width = min(width, cnt);

                    // Is height ke liye width possible rectangles hain
                    sum += width;
                }
            }
        }

        return sum;
    }
};
