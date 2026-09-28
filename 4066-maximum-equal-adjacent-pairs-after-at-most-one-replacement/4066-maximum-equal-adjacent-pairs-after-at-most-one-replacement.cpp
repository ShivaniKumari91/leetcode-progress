class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
          int existing = 0;

        map<pair<int,int>, int> mp;

        // Count existing equal pairs
        // and store different adjacent pairs
        for(int i = 0; i < nums.size() - 1; i++) {

            if(nums[i] == nums[i+1]) {
                existing++;
            }
            else {
                mp[{nums[i], nums[i+1]}]++;
            }
        }

        int maxi = 0;

        // For every (a,b), check both directions:
        // (a,b) + (b,a)
        for(auto &it : mp) {

            int count = it.second
                      + mp[{it.first.second, it.first.first}];

            maxi = max(maxi, count);
        }

        // Existing pairs + maximum newly created pairs
        return existing + maxi;
        
    }
};