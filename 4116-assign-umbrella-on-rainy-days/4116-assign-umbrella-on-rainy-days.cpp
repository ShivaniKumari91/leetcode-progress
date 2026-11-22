class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();

        int ac = 0;
        int bc = 0;

        vector<string> ans(n);

        for(int i = 0; i < n; i++){
            if (rain[i] == 1 && i < n-1 && rain[i + 1] == 1){
                
                if(ac <= bc){
                    ans[i] = "Alice";
                    ac++; 
                }

                else{
                    ans[i] = "Bob";
                    bc++;
                }

                
            }

            else if(rain[i] == 1){
                ans[i] = "Bob";
                bc++;
            }

            else if(rain[i] == 0){
                ans[i] = "None";
            }


        }
        return ans;
        
    }
};