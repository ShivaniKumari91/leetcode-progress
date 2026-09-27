class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        // NOTE: Use ordered map because we need values in ASCENDING order
        map<int, int> mp;

        // Store frequency of each value
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        vector<int> ans;

        // Repeat operation until no element is left
        while(true) {

            bool found = false;

            // NOTE: map automatically gives keys in ascending order
            // NOTE: & is used because we need to MODIFY the frequency
            for(auto &it : mp) {

                if(it.second > 0) {

                    ans.push_back(it.first);
                    it.second--;

                    // IMPORTANT: found = true must be INSIDE the if
                    found = true;
                }
            }

            // No element was processed -> all frequencies are 0
            if(found == false) {
                break;
            }
        }

        return ans;
    }
};

/*
IMPORTANT POINTS:

1. map<int,int> -> stores frequency + keeps keys sorted.
2. it.first  -> number
3. it.second -> frequency
4. auto &it   -> reference, so it.second-- modifies the map.
5. Each round takes ONE occurrence of every distinct value.
6. found tells whether any element was processed in the current round.
7. found = true must be inside if(it.second > 0).
8. If found remains false -> all frequencies are 0 -> break.
9. Time:  O(n * k), where k = number of distinct values.
10. Space: O(k).
*/