class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;  // Unmatched opening brackets '('
        int ans = 0;  // Unmatched closing brackets ')'

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '('){
                // Store the opening bracket for future matching
                cnt++;
            }
            else{
                // If an opening bracket is available, match it
                if(cnt > 0){
                    cnt--;
                }
                else{
                    // No opening bracket available, so add '('
                    ans++;
                }
            }
        }

        // Add ')' for all unmatched opening brackets
        return ans + cnt;
    }
};