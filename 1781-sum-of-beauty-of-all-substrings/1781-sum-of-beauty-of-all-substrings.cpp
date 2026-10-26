
class Solution {
public:
    int solve(string s) {
        // Store frequency of each character (a to z)
        vector<int> freq(26, 0);

        // Count frequency of every character in the substring
        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        // Find the maximum frequency among all characters
        int maxFreq = *max_element(freq.begin(), freq.end());

        // Initialize minimum frequency with a very large value
        int minFreq = INT_MAX;

        // Find the minimum frequency, ignoring absent characters
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                minFreq = min(minFreq, freq[i]);
            }
        }

        // Beauty = maximum frequency - minimum frequency
        return maxFreq - minFreq;
    }

    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        // Fix the starting index of the substring
        for(int i = 0; i < n; i++) {

            // Extend the substring by moving the ending index
            for(int j = i; j < n; j++) {

                // Calculate beauty of the current substring
                // and add it to the total sum
                sum += solve(s.substr(i, j - i + 1));
            }
        }

        // Return the sum of beauties of all substrings
        return sum;
    }
};
