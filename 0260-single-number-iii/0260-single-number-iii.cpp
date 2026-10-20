class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        // Step 1: XOR all elements
        // Duplicate numbers cancel each other
        // xorr = XOR of two unique numbers
        long long xorr = 0;

        for(int i = 0; i < n; i++) {
            xorr = xorr ^ nums[i];
        }

        // Step 2: Find the rightmost set bit
        // This bit is different in the two unique numbers
        int rightmost = (xorr & (xorr - 1)) ^ xorr;

        int b1 = 0;
        int b2 = 0;

        // Step 3: Divide numbers into two groups
        for(int i = 0; i < n; i++) {

            // If the selected bit is 1
            if(nums[i] & rightmost) {
                b1 = b1 ^ nums[i];
            }
            // If the selected bit is 0
            else {
                b2 = b2 ^ nums[i];
            }
        }

        // Each group gives one unique number
        return {b1, b2};
    }
};