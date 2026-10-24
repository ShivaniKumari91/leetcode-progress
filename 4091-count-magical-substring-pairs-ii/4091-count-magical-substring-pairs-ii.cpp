class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();

        // rc[j][c] = number of substrings starting at index j
        // that contain exactly c distinct characters.
        vector<vector<int>> rc(n, vector<int>(27, 0));

        // fp[ch] = first occurrence of character ch at or after j.
        // n means the character has not appeared yet.
        vector<int> fp(26, n);

        // Build right-substring counts from right to left.
        for (int j = n - 1; j >= 0; j--) {
            fp[s[j] - 'a'] = j;

            // Sort a copy of first-occurrence positions.
            // Do not sort fp itself, because we need its original mapping.
            auto p = fp;
            sort(p.begin(), p.end());

            // p[d] is the position where the (d+1)-th
            // distinct character first appears.
            for (int d = 0; d < 26 && p[d] < n; d++) {

                // Next distinct character's first occurrence.
                // If there is no next character, use n.
                int nextPos = (d + 1 < 26) ? p[d + 1] : n;

                // Number of possible ending positions that give
                // exactly d+1 distinct characters.
                rc[j][d + 1] = nextPos - p[d];
            }
        }

        // lp[ch] = last occurrence of character ch at or before j.
        // -1 means the character has not appeared yet.
        vector<int> lp(26, -1);

        long long ans = 0;

        // j is the last index of the left substring.
        // The right substring starts at j+1.
        for (int j = 0; j < n - 1; j++) {
            lp[s[j] - 'a'] = j;

            // Sort a copy in descending order.
            // This gives last-occurrence positions from right to left.
            auto p = lp;
            sort(p.rbegin(), p.rend());

            // Count left substrings by their number of distinct characters.
            for (int d = 0; d < 26 && p[d] > -1; d++) {

                // Next smaller last-occurrence position.
                // -1 acts as the boundary before the string starts.
                int nextPos = (d + 1 < 26) ? p[d + 1] : -1;

                // Number of left substrings ending at j
                // with exactly d+1 distinct characters.
                int leftCount = p[d] - nextPos;

                // Number of right substrings starting at j+1
                // with exactly d+1 distinct characters.
                int rightCount = rc[j + 1][d + 1];

                // Every such left substring pairs with every
                // such right substring, so multiply the counts.
                ans += 1LL * leftCount * rightCount;
            }
        }

        return ans;
    }
};

//String s = "aba", n = 3
//Loop 1: Build rc
//j	Right substring	rc[j][1]	rc[j][2]
//2	"a"	1	0
//1	"ba"	1	1
//0	"aba"	1	2
//Loop 2: Count magical pairs
//Split j	Left substrings	Right substrings	Added
//0	"a" (1 distinct)	"b", "ba" (1 distinct each)	2
//1	"a", "ab"	"a"	1
//Total ans = 2 + 1 = 3? Let's correct the counting: for s = "aba", valid pairs are "a" | "b" and "b" | "a"? Actually split j=0 gives "a" | "b" and "a" | "ba" (both distinct counts 1 vs 1 and 1 vs 2 respectively, so only the first is valid); split j=1 gives "a" | "a" and "ab" | "a" (only "a" | "a" is valid). Thus answer = 2.