class Solution {
public:

    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = 0;

        // Prefix sum
        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Case 1: Without negation
        unordered_map<int, int> first;

        first[0] = 0;

        for(int i = 1; i <= n; i++) {

            int rem = prefix[i] % k;
            if(rem < 0) rem += k;

            if(first.count(rem)) {
                ans = max(ans, i - first[rem]);
            }
            else {
                first[rem] = i;
            }
        }

        // Case 2: Negate nums[x]
        for(int x = 0; x < n; x++) {

            // l <= x hona chahiye
            // Isliye prefix[0] se prefix[x] tak store karo
            unordered_map<int, int> earliest;

            for(int l = 0; l <= x; l++) {

                int rem = prefix[l] % k;
                if(rem < 0) rem += k;

                if(!earliest.count(rem)) {
                    earliest[rem] = l;
                }
            }

            // r >= x hona chahiye
            for(int r = x; r < n; r++) {

                // Need:
                // prefix[r+1] - prefix[l] - 2*nums[x] ≡ 0
                //
                // prefix[l] ≡ prefix[r+1] - 2*nums[x]

                long long value =
                    prefix[r + 1] - 2LL * nums[x];

                int need = value % k;

                if(need < 0) need += k;

                if(earliest.count(need)) {

                    int l = earliest[need];

                    ans = max(ans, r - l + 1);
                }
            }
        }

        return ans;
    }
};