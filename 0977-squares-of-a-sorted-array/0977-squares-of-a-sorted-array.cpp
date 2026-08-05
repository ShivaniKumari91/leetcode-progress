class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0, right = n - 1, index = n - 1;
        

        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];

            if (leftSq > rightSq) {
                result[index] = leftSq;
                left++;
            } else {
                result[index] = rightSq;
                right--;
            }

            index--;
        }

        return result;
    }
};