class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        int maxLength = 0;

        // Fix the starting point of the subarray
        for (int left = 0; left < n; left++) {

            // Stores (2 * nums[right]) % k
            // for all elements present in current subarray
            unordered_set<int> doubleRemainders;

            long long currentSum = 0;

            // Expand the subarray towards right
            for (int right = left; right < n; right++) {

                // Add current element to the subarray sum
                currentSum += nums[right];


                // If we negate x:
                //
                // New sum = currentSum - 2*x
                //
                // For new sum to be divisible by k:
                //
                // (currentSum - 2*x) % k == 0
                //
                // Therefore:
                //
                // currentSum % k == (2*x) % k
                //
                // So store (2*x) % k in the set.
                
                long long doubleRemainder =
                    ((2LL * nums[right]) % k + k) % k;

                doubleRemainders.insert(doubleRemainder);


                // Find remainder of the current subarray sum
                long long sumRemainder =
                    (currentSum % k + k) % k;


                // CASE 1:
                // currentSum itself is divisible by k
                //
                // CASE 2:
                // There is some element x in the subarray
                // such that (2*x) % k == currentSum % k
                //
                // In CASE 2, negating that x makes the sum divisible by k.
                
                if (sumRemainder == 0 ||
                    doubleRemainders.find(sumRemainder) != doubleRemainders.end()) {

                    maxLength = max(maxLength, right - left + 1);
                }
            }
        }

        return maxLength;
    }
};