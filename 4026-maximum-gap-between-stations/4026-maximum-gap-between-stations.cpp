class Solution {
public:
    int maximumGap(string skill, string station) {
        int m = skill.size();
        int n = station.size();

        vector<int> left(m);
        vector<int> right(m);

        int i = 0;

        for (int ind = 0; ind < n && i < m; ind++) {
            if (skill[i] == station[ind]) {
                left[i] = ind;
                i++;
            }
        }

        i = m - 1;

        for (int ind = n - 1; ind >= 0 && i >= 0; ind--) {
            if (skill[i] == station[ind]) {
                right[i] = ind;
                i--;
            }
        }

        int maxi = 0;

        for (int i = 1; i < m; i++) {
            int gap = right[i] - left[i - 1];
            maxi = max(maxi, gap);
        }

        return maxi;
    }
};