
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for(int i = 2; i <= n; i++) {
            string temp = "";
            int j = 0;

            while(j < ans.size()) {
                int cnt = 1;

                while(j + 1 < ans.size() && ans[j] == ans[j + 1]) {
                    cnt++;
                    j++;
                }

                temp += to_string(cnt) + ans[j];
                j++;
            }

            ans = temp;
        }

        return ans;
    }
};
