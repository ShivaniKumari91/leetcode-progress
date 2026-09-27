class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        vector<int> ans;

        while(true){
            bool found = false;

            for(auto &it:mp){
                if(it.second > 0){
                    ans.push_back(it.first);
                    it.second--;
                    found = true;
                }
                
            }

            if(found == false){
                break;
            }

        }
        return ans;
        
    }
};