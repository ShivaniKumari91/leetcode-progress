
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int start = 0; // Longest palindrome ka starting index
        int maxi = 1;  // Longest palindrome ki maximum length

        for (int i = 0; i < n; i++) {

            // Case 1: Odd length palindrome
            // Ek character ko center maante hain
            int l = i;
            int r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {

                // Current palindrome ki length
                int len = r - l + 1;

                // Agar current palindrome longest hai, update karo
                if (len > maxi) {
                    maxi = len;
                    start = l;
                }

                // Center se ek-ek position bahar expand karo
                l--;
                r++;
            }

            // Case 2: Even length palindrome
            // Do adjacent characters ke beech center maante hain
            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {

                int len = r - l + 1;

                if (len > maxi) {
                    maxi = len;
                    start = l;
                }

                // Dono taraf expand karo
                l--;
                r++;
            }
        }

        // Starting index aur length se longest substring return karo
        return s.substr(start, maxi);
    }
};
