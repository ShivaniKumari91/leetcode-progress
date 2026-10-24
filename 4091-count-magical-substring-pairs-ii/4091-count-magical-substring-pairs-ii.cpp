using ll = long long;

class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();

        // rc[j][d] = substrings starting at j
        // having exactly d distinct characters
        vector<vector<int>> rc(n, vector<int>(27, 0));

        // fp[c] = first occurrence of character c
        // at or after current index j
        vector<int> fp(26, n);

        // Process from right to left
        for (int j = n - 1; j >= 0; j--) {
            fp[s[j] - 'a'] = j;

            auto p = fp;
            sort(p.begin(), p.end());

            for (int d = 0; d < 26 && p[d] < n; d++) {
                int nextPos = (d + 1 < 26) ? p[d + 1] : n;

                rc[j][d + 1] = nextPos - p[d];
            }
        }

        // lp[c] = last occurrence of character c
        // at or before current index j
        vector<int> lp(26, -1);

        ll ans = 0;

        // Process split positions from left to right
        for (int j = 0; j < n - 1; j++) {
            lp[s[j] - 'a'] = j;

            auto p = lp;
            sort(p.rbegin(), p.rend());

            for (int d = 0; d < 26 && p[d] > -1; d++) {
                int nextPos = (d + 1 < 26) ? p[d + 1] : -1;

                int leftCount = p[d] - nextPos;
                int rightCount = rc[j + 1][d + 1];

                ans += 1LL * leftCount * rightCount;
            }
        }

        return ans;
    }
};