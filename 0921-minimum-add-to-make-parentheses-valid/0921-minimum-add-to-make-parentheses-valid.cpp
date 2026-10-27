class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int ans = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cnt++;
            }
            else{
                if(cnt > 0){
                    cnt--;
                }
                else{
                    ans++;
                }
            }
        }

        return cnt + ans;
        
    }
};