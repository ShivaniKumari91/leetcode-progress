
class Solution {
public:
    // Rearrange digits in descending order to get maximum number
    int f(int n) {
        vector<int> ds;

        while (n > 0) {
            ds.push_back(n % 10);
            n = n / 10;
        }

        sort(ds.begin(), ds.end(), greater<int>());

        int maxi = 0;

        // Build the maximum number from sorted digits
        for (int i = 0; i < ds.size(); i++) {
            maxi = maxi * 10 + ds[i];
        }

        return maxi;
    }

    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> gain;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int changeVal = f(nums[i]);

            // Gain obtained by rearranging this element
            gain.push_back(changeVal - nums[i]);
        }

        // Sort gains in descending order
        sort(gain.begin(), gain.end(), greater<int>());

        long long changeSum = 0;

        // Take at most k positive gains
        for (int i = 0; i < min(k, n); i++) {
            if (gain[i] <= 0) {
                break;
            }

            changeSum += gain[i];
        }

        return sum + changeSum;
    }
};
