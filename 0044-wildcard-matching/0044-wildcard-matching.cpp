class Solution {
public:
    bool isMatch(string s, string p) {

        int n = p.size();
        int m = s.size();

        vector<bool> prev(m + 1, false);
        vector<bool> cur(m + 1, false);

        // Base case
        // Empty pattern + empty string
        prev[0] = true;

        // Empty pattern + non-empty string
        for(int j = 1; j <= m; j++) {
            prev[j] = false;
        }

        for(int i = 1; i <= n; i++) {

            // Empty string
            cur[0] = true;

            // Pattern should contain only '*'
            for(int j = 1; j <= i; j++) {
                if(p[j - 1] != '*') {
                    cur[0] = false;
                    break;
                }
            }

            for(int j = 1; j <= m; j++) {

                // Same character OR '?'
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    cur[j] = prev[j - 1];
                }

                // '*'
                else if(p[i - 1] == '*') {
                    cur[j] = prev[j] || cur[j - 1];
                }

                else {
                    cur[j] = false;
                }
            }

            prev = cur;
        }

        return prev[m];
    }
};