
class Solution {
public:
    string countAndSay(int n) {
        // Base case: 1st string is always "1"
        string ans = "1";

        // Start from 2 because ans already stores the 1st string
        for(int i = 2; i <= n; i++) {
            string temp = "";  // Stores the next string
            int j = 0;

            while(j < ans.size()) {
                int cnt = 1;  // Current character occurs at least once

                // Count consecutive occurrences of the same character
                while(j + 1 < ans.size() && ans[j] == ans[j + 1]) {
                    cnt++;
                    j++;
                }

                // Append count followed by the character
                temp += to_string(cnt) + ans[j];

                // Move to the next group of characters
                j++;
            }

            // The newly generated string becomes the current string
            ans = temp;
        }

        // Return the nth string
        return ans;
    }
};
