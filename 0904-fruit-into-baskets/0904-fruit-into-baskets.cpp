class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> f;
        int low = 0; 
        int high = 0;
        int n = fruits.size();
        int res = INT_MIN;

        for(int high = 0; high < n; high++){
            f[fruits[high]]++;

            while (f.size() > 2){
                f[fruits[low]]--;

                if(f[fruits[low]] == 0){
                    f.erase(fruits[low]);
                }
                low++;

                
            }

            

            int length = high - low + 1;

            res = max(res,length);

            
            

           

            
        }
        
        return res;
        
    }
};