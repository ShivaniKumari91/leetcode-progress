
class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Har possible starting index choose karo
        for (int i = 0; i < n; i++) {

            // Current subarray ki frequencies
            unordered_map<int, int> freq;

            // Distinct elements ko first appearance order mein store karo
            vector<int> order;

            // Subarray ko right side mein extend karo
            for (int j = i; j < n; j++) {

                // Agar element pehli baar aaya hai
                if (freq[nums[j]] == 0) {
                    order.push_back(nums[j]);
                }

                // Current element ki frequency increase karo
                freq[nums[j]]++;

                // Maan lo current subarray valid hai
                bool valid = true;

                // Har distinct element ki expected frequency check karo
                for (int k = 0; k < order.size(); k++) {

                    // First element ki frequency 1,
                    // second ki 2, third ki 3 honi chahiye
                    if (freq[order[k]] != k + 1) {
                        valid = false;
                        break;
                    }
                }

                // Agar saari frequencies match kar gayin
                if (valid) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
