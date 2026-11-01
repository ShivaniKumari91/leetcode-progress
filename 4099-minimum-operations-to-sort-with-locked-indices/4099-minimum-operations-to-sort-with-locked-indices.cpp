class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {

        int n = nums.size();

        // Difference array to mark inversion ranges
        vector<int> diff(n + 1, 0);

        int swaps = 0;

        // Step 1: Find all inversions
        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                // If left element is greater, it forms an inversion
                if(nums[i] > nums[j]) {

                    swaps++;

                    // Mark the range [i, j] in difference array
                    diff[i]++;
                    diff[j + 1]--;
                }
            }
        }

        // Step 2: Calculate active inversion ranges
        int active = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++) {

            // Update the number of ranges covering current index
            active += diff[i];

            // Count locked indices covered by at least one inversion range
            if(active > 0 && locked[i] == 1) {
                cnt++;
            }
        }

        // Step 3: Check whether unlock limit is exceeded
        if(cnt > k) {
            return -1;
        }

        // Count swaps and unlock operations
        return swaps + cnt;
    }
};