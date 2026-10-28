
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

        for (int i = 1; i < n; i++) {
            power = (power * base) % mod;
        }

        for (int i = 0; i < n; i++) {
            hash1 = (hash1 * base + a[i]) % mod;
            hash2 = (hash2 * base + b[i]) % mod;
        }

        for (int i = 0; i <= m - n; i++) {
            if (hash1 == hash2) {
                if (a.substr(i, n) == b) {
                    return true;
                }
            }

            if (i < m - n) {
                hash1 = (hash1 - (a[i] * power) % mod + mod) % mod;
                hash1 = (hash1 * base + a[i + n]) % mod;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string tmp = a;
        int ans = 1;

        while (a.size() < b.size()) {
            a += tmp;
            ans++;
        }

        if (check(a, b)) {
            return ans;
        }

        a += tmp;

        if (check(a, b)) {
            return ans + 1;
        }

        return -1;
    }
};
