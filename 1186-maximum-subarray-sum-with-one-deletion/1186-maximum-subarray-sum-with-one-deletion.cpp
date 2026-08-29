class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int i = 0;
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        int res = arr[0];

        for(int i = 1; i < arr.size(); i++){
            int prevNodel = nodelete;
            int prevOnedel = onedelete;

            nodelete = max((nodelete + arr[i]),arr[i]);

            int v2;

            if(onedelete == INT_MIN){
                v2 = arr[i];
            }
            else{
                v2 = prevOnedel + arr[i];
            }

            onedelete  = max(prevNodel,v2);

            res = max(res,max(onedelete,nodelete));

        }
        return res;
        
    }
};