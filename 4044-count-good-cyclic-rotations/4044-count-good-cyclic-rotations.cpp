class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        long long total = 0;
        for (int x : nums) {
            total += x;
        }

        long long first = 0;

        // Initial window: low = 0, high = half-1
        int low = 0;
        int high = half - 1;

        for (int i = low; i <= high; i++) {
            first += nums[i];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            long long second = total - first;

            if (first > second) {
                ans++;
            }

            // Slide window
            first -= nums[low];

            low++;
            high++;

            // Circular array
            first += nums[high % n];
        }

        return ans;
    }
};