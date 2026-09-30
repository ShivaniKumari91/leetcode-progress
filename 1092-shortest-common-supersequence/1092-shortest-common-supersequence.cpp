
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        // dp[i][j] = LCS length of str1[0...i-1] and str2[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // LCS Tabulation
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(str1[i - 1] == str2[j - 1]) {

                    // Same character -> take once in SCS
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                }
                else {

                    // Take maximum LCS from either direction
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }


        // Now reconstruct SCS using the LCS DP table
        int i = n;
        int j = m;

        string ans = "";

        while(i > 0 && j > 0) {

            // Same character -> add only once
            if(str1[i - 1] == str2[j - 1]) {

                ans += str1[i - 1];

                i--;
                j--;
            }

            // Upper cell has bigger LCS -> take from str1
            else if(dp[i - 1][j] > dp[i][j - 1]) {

                ans += str1[i - 1];

                i--;
            }

            // Left cell is bigger OR both are equal
            // Equal case -> this code chooses str2
            else {

                ans += str2[j - 1];

                j--;
            }
        }


        // If str1 is left, add remaining characters
        while(i > 0) {

            ans += str1[i - 1];
            i--;
        }

        // If str2 is left, add remaining characters
        while(j > 0) {

            ans += str2[j - 1];
            j--;
        }


        // Reconstruction was done from end -> reverse
        reverse(ans.begin(), ans.end());

        return ans;
    }
};


//### ⭐ Main points to remember


//1. First make LCS DP table.

//2. Start reconstruction:
      // i = n
       //j = m

//3. Same character:
       //str1[i-1] == str2[j-1]
       //→ add once
      // → i--, j--

//4. Different characters:
       //dp[i-1][j] > dp[i][j-1]
       //→ take str1[i-1]
       //→ i--

       //Otherwise
       //→ take str2[j-1]
       //→ j--

//5. If both DP values are equal:
      // else runs
      // → current code takes str2

//6. Add remaining characters.

//7. Reverse because reconstruction starts from the end.

//TC = O(n × m)
//SC = O(n × m)

