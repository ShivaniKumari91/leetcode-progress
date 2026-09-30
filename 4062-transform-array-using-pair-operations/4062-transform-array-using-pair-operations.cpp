class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        if(source == target) return true;
        int n = source.size();
        int m = target.size();
        
        long long sum1 = 0;
        long long sum2 = 0;

        for(int i = 0; i<n; i++) {
            sum1 = sum1 + source[i];
        }
        for(int j = 0; j<m; j++){
            sum2 = sum2 + target[j];
        }

        if(sum1 == sum2) return true;
        else return false;
        
    }
};