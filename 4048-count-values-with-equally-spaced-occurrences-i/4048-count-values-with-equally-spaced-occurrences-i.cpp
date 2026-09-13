class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;

        for(int i = 0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int cnt = 0;
        for(auto x:mp){
            if(x.second.size()==3){
                int i1 = x.second[0];
                int i2 = x.second[1];
                int i3 = x.second[2];

                if(i2-i1 == i3-i2){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};