
class Solution {
public:
    int getValue(char ch) {
        if(ch == 'I') return 1;
        else if(ch == 'V') return 5;
        else if(ch == 'X') return 10;
        else if(ch == 'L') return 50;
        else if(ch == 'C') return 100;
        else if(ch == 'D') return 500;
        else if(ch == 'M') return 1000;

        return 0;
    }

    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int curr = getValue(s[i]);

            // Check if next character exists
            if(i + 1 < n) {
                int next = getValue(s[i + 1]);

                // Current value smaller than next: subtract
                if(curr < next) {
                    ans -= curr;
                }
                else {
                    ans += curr;
                }
            }
            else {
                // Last character: simply add its value
                ans += curr;
            }
        }

        return ans;
    }
};
