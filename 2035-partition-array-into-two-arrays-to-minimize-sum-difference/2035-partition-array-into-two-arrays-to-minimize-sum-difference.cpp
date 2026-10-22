class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();

        int S = accumulate(begin(nums),end(nums),0);

        int n = N/2;
        int n1 = n;
        int n2 = n;

        unordered_map<int,vector<int>> sumsLeft;
        unordered_map<int,vector<int>> sumsRight;

        for(int mask = 0; mask<(1<<n1); mask++){
            int s = 0;
            int count = 0;

            for(int i = 0; i<n1; i++){
                if(mask & (1 << i)){
                    s += nums[i];
                    count++;
                }
            }
            sumsLeft[count].push_back(s);
        }

        for(int mask = 0; mask<(1<<n1); mask++){
            int s = 0;
            int count = 0;

            for(int i = 0; i<n1; i++){
                if(mask & (1 << i)){
                    s += nums[n+i];
                    count++;
                }
            }
            sumsRight[count].push_back(s);
        }
        
        for(int count = 0; count <= n2; count++){
            sort(begin(sumsRight[count]),end(sumsRight[count]));
        }

        int minValue = INT_MAX;

        for(int k  =0; k < n1; k++){
            int m = n-k;

            for(int leftSubSum : sumsLeft[k]){
                int need = (S - 2*leftSubSum)/2;

                int low = lower_bound(begin(sumsRight[m]),end(sumsRight[m]),need) - begin(sumsRight[m]);

                if(low < sumsRight[m].size()){
                    int rightSubSum = sumsRight[m][low];
                    minValue = min(minValue,abs(2*(leftSubSum + rightSubSum)- S));
                }

                if(low-1 >= 0){
                    int rightSubSum = sumsRight[m][low-1];
                    minValue = min(minValue,abs(2*(leftSubSum + rightSubSum)- S));
                }
            }

            


        }
        return minValue;

    }
};