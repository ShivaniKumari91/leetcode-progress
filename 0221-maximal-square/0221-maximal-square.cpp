class Solution {
public:

    bool check(vector<vector<int>>& prefix, int m, int n, int k) {

        for (int i = k; i <= m; i++) {
            for (int j = k; j <= n; j++) {

                int sum = prefix[i][j]
                        - prefix[i - k][j]
                        - prefix[i][j - k]
                        + prefix[i - k][j - k];

                if (sum == k * k) {
                    return true;
                }
            }
        }

        return false;
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        // Build prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                int value = matrix[i - 1][j - 1] - '0';

                prefix[i][j] = value
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        // Binary Search
        int low = 1;
        int high = min(m, n);
        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(prefix, m, n, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans * ans;
    }
};