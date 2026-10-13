class Solution {
public:
    bool isPrime(int num) {
        //if(num < 2) return false;

        for(int j = 2; j * j <= num; j++) {
            if(num % j == 0) return false;
        }

        return true;
    }

    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        int sum = 0;

        for(int i = 2; i <= n; i++) {
            if(!isPrime(i)) continue;

            if(sum + i > s) break;

            sum = sum + i;
            ans.push_back(i);
        }

        return ans;
    }
};