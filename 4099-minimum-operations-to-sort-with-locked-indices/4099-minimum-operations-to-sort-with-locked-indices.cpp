
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {

        int ans = 0;
        int n = nums.size();

        // Outer loop: Repeat passes to sort the array
        for(int pass = 0; pass < n; pass++) {

            // Check adjacent elements
            for(int i = 0; i < n - 1; i++) {

                // If elements are in wrong order
                if(nums[i] > nums[i + 1]) {

                    // Unlock left index if locked
                    if(locked[i] == 1) {
                        if(k == 0) return -1;

                        ans++;
                        locked[i] = 0;
                        k--;
                    }

                    // Unlock right index if locked
                    if(locked[i + 1] == 1) {
                        if(k == 0) return -1;

                        ans++;
                        locked[i + 1] = 0;
                        k--;
                    }

                    // Swap adjacent elements
                    swap(nums[i], nums[i + 1]);
                    ans++;
                }
            }
        }

        return ans;
    }
};
