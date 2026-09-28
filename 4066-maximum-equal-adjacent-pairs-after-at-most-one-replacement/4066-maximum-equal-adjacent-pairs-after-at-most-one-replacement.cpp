class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,int>, int> mp;

        int existing = 0;

        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                existing++;
            }
            else{
                mp[{nums[i],nums[i+1]}]++;
            }

        }

        int maxi = 0;

        for(auto it:mp){
            int count = it.second + mp[{it.first.second,it.first.first}];
            maxi = max(maxi,count);
        }
        return maxi + existing;
        
    }
};