class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size();
        int maxgreen = *max_element(lights.begin(),lights.end());
        int wt;
        int ans = INT_MIN;


        for(int i = 0; i<n; i++){
            int r = arrivalTime[i] % period;

            if(r < maxgreen){
                wt = 0;

            }
            else{
                wt = period - r;
            }
            ans = max(ans,wt);
        }
        return ans;
        
    }
};