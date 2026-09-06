class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();

        int score = 0;

        // Count equal adjacent characters
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1])
                score++;
        }

        // Check the circular pair
        if (s[n - 1] == s[0])
            score++;

        if (k == score)
            return n - score;

        if (k == score - 1)
            return score;

        return 0;
    }
};