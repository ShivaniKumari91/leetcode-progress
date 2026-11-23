
class Solution {
public:
    long long minCost(vector<int>& nums) {

        int n = nums.size();

        long long sum = 0;
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        int cnt = 0;

        // Check only interior elements
        for(int i = 1; i < n-1; i++) {

            if(nums[i] < 0) {
                sum += nums[i];
                maxi = max(maxi, (long long)nums[i]);
                cnt++;
            }
            else {
                mini = min(mini, (long long)nums[i]);
            }
        }

        // If negative count is odd
        if(cnt % 2 == 1) {

            long long option1 = LLONG_MAX;
            long long option2 = LLONG_MAX;

            // Remove one negative number
            if(maxi != LLONG_MIN) {
                option1 = sum - maxi;
            }

            // Add one non-negative number
            if(mini != LLONG_MAX) {
                option2 = sum + mini;
            }

            sum = min(option1, option2);
        }

        // First and last elements are always endpoints
        return sum + nums[0] + nums[n-1];
    }
};
