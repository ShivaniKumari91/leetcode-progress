class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        int cnt = 0;   // Current depth of nested parentheses
        int maxi = 0;  // Maximum depth encountered so far

        for(int i = 0; i < n; i++) {

            // Opening bracket increases the current depth
            if(s[i] == '(') {
                cnt++;

                // Update maximum depth whenever depth increases
                maxi = max(maxi, cnt);
            }

            // Closing bracket decreases the current depth
            else if(s[i] == ')') {
                cnt--;
            }
        }

        // Return the maximum nesting depth
        return maxi;
    }
};