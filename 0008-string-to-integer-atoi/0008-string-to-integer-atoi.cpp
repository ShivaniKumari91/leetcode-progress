class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int  i = 0;
        int sign = 1;

        while(i<n && s[i] == ' '){
            i++;
        }

        if(i<n && s[i]== '+'|| s[i]== '-'){
            if(s[i]== '-'){
                sign = -1;
            }
            i++;
        }

        long long ans = 0 ;

        while(i<n && isdigit(s[i])){
            int digit = s[i]-'0';

            if(ans > INT_MAX/10 || ans == INT_MAX/10 && digit > 7){
                if(sign == 1) {

                    return INT_MAX;
                }
                else{
                    return INT_MIN;
                } 
            }

            ans = ans * 10 + digit;
            i++;
        }
        return sign*ans;


        
    }
};