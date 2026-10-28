class Solution {
public:
    bool check(string &a, string &b) {
        int m = a.size();
        int n = b.size();

        if (n > m) return false;

        long long base = 10;
        long long mod = 101;

        long long power = 1;
        long long hash1 = 0;
        long long hash2 = 0;

        // Calculate base^(n-1) % mod.
        // Ye first character ko remove karne ke kaam aayega.
        for (int i = 1; i < n; i++) {
            power = (power * base) % mod;
        }

        // Calculate the hash of the first window of a
        // and the hash of the complete pattern b.
        for (int i = 0; i < n; i++) {
            hash1 = (hash1 * base + a[i]) % mod;
            hash2 = (hash2 * base + b[i]) % mod;
        }

        // Slide the window over string a.
        for (int i = 0; i <= m - n; i++) {

            // Hash match hone par actual substring bhi check karo,
            // because different strings can have the same hash.
            if (hash1 == hash2) {
                if (a.substr(i, n) == b) {
                    return true;
                }
            }

            // Update hash only if the next window exists.
            if (i < m - n) {

                // Remove the outgoing character a[i].
                hash1 = (hash1 - (a[i] * power) % mod + mod) % mod;

                // Shift the remaining hash and add incoming character.
                // a[i+n] is the next character entering the window.
                hash1 = (hash1 * base + a[i + n]) % mod;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string tmp = a;
        int ans = 1;

        // Repeat a until its length becomes at least b's length.
        while (a.size() < b.size()) {
            a += tmp;
            ans++;
        }

        // Check whether b exists in the current repeated string.
        if (check(a, b)) {
            return ans;
        }

        // One extra repetition may allow the match across the boundary.
        a += tmp;

        if (check(a, b)) {
            return ans + 1;
        }

        return -1;
    }
};