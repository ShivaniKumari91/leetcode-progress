
class Solution {
public:
    string countAndSay(int n) {
        // Base case
        if(n == 1) {
            return "1";
        }

        // Get the previous string using recursion
        string ans = countAndSay(n - 1);

        // Generate the next string
        string temp = "";
        int j = 0;

        while(j < ans.size()) {
            int cnt = 1;

            // Count consecutive same characters
            while(j + 1 < ans.size() && ans[j] == ans[j + 1]) {
                cnt++;
                j++;
            }

            // Append count followed by the character
            temp += to_string(cnt) + ans[j];

            j++;
        }

        return temp;
    }
};
