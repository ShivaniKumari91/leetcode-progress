
class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();

        long long ans = LLONG_MAX;

        int i = 0;

        while(i < n) {

            int j = i;

            // Find consecutive equal elements
            while(j + 1 < n && nums[j] == nums[j+1]) {
                j++;
            }

            // Group must contain a valid internal index
            if(j >= 1 && i <= n-2) {

                long long x = nums[i];

                // Prefix cost + suffix cost
                long long cost = 1LL * (i + n-j-1) * x;

                ans = min(ans, cost);
            }

            // Move to next group
            i = j + 1;
        }

        return ans;
    }
};
