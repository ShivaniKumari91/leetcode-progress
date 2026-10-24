class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        long long ans = 0;

        // j is the split point:
        // Left substring  = s[i...j]
        // Right substring = s[j+1...k]
        // This ensures i <= j < k < n
        for (int j = 0; j < n - 1; j++) {

            // Track frequency of each character (a-z)
            vector<int> leftFreq(26, 0);
            vector<int> rightFreq(26, 0);

            // left[d]  = number of left substrings
            //            having exactly d distinct characters
            // right[d] = number of right substrings
            //            having exactly d distinct characters
            // Size 27 allows indices 0 to 26.
            vector<int> left(27, 0);
            vector<int> right(27, 0);

            int distinct = 0;

            // Scan left substrings ending at j.
            // i moves backwards, so i <= j is always satisfied.
            for (int i = j; i >= 0; i--) {

                // Increase distinct only if this character
                // has not appeared in the current substring.
                if (leftFreq[s[i] - 'a'] == 0) {
                    distinct++;
                }

                // Record this character's frequency.
                leftFreq[s[i] - 'a']++;

                // Count this substring in its distinct-count group.
                // This happens for EVERY substring, even if
                // the character was repeated.
                left[distinct]++;
            }

            // Reset distinct before scanning the right side.
            distinct = 0;

            // Scan right substrings starting at j+1.
            // k starts at j+1, so k > j is always satisfied.
            for (int k = j + 1; k < n; k++) {

                // Increase distinct only for a new character.
                if (rightFreq[s[k] - 'a'] == 0) {
                    distinct++;
                }

                // Record this character's frequency.
                rightFreq[s[k] - 'a']++;

                // Count this right substring by its distinct count.
                right[distinct]++;
            }

            // Match left and right substrings with equal
            // numbers of distinct characters.
            for (int d = 1; d <= 26; d++) {

                // Every left choice can pair with every right choice.
                // Multiplication counts all such combinations.
                ans += 1LL * left[d] * right[d];
            }
        }

        // Return the total number of magical pairs.
        return (int)ans;
    }
};