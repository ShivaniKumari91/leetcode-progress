class Solution {
public:
    int fun(int n) {
        int sum = 0;

        while(n > 0) {
            int dig = n % 10;
            n = n / 10;

            sum += dig * dig;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(true) {
            slow = fun(slow);
            fast = fun(fun(fast));

            if(slow == fast && slow != 1)
                return false;

            if(slow == 1)
                return true;
        }
    }
};