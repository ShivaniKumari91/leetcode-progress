class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int l = 0;
        int h = 0;
        int maxi  = 0;

        while(h < n){
            mp[s[h]]++;

            while(mp[s[h]] > 1){
                mp[s[l]]--;
                l++;
            }

            maxi = max(maxi,h-l+1);
            h++;

        }

        return maxi;
        
    }
};