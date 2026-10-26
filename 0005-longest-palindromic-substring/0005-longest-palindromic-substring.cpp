
class Solution {
public:
    vector<vector<int>> dp;

    bool checkPalindrome(string &s, int start, int end) {

        // Base case: 0 ya 1 character hamesha palindrome hota hai
        if (start >= end) return true;

        // Agar is substring ka answer pehle calculate ho chuka hai
        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        // Agar outer characters different hain, toh palindrome nahi hai
        if (s[start] != s[end]) {
            return dp[start][end] = false;
        }

        // Outer characters equal hain, ab andar ka substring check karo
        return dp[start][end] =
            checkPalindrome(s, start + 1, end - 1);
    }

    string longestPalindrome(string s) {
        int n = s.size();

        // -1 means abhi palindrome status calculate nahi hua
        // 0 means false, 1 means true
        dp.assign(n, vector<int>(n, -1));

        int start = 0; // Longest palindrome ka starting index
        int maxi = 1;  // Longest palindrome ki maximum length

        // Har possible starting index choose karo
        for (int i = 0; i < n; i++) {

            // Har possible ending index choose karo
            for (int j = i; j < n; j++) {

                // Check karo ki s[i...j] palindrome hai ya nahi
                if (checkPalindrome(s, i, j)) {

                    int len = j - i + 1;

                    // Agar current palindrome longest hai, update karo
                    if (len > maxi) {
                        maxi = len;
                        start = i;
                    }
                }
            }
        }

        // Starting index se maxi characters return karo
        return s.substr(start, maxi);
    }
};
