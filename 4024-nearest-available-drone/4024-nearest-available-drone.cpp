class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int mindist = INT_MAX;
        int index = 0;

        for(auto it: drones){
            int dist = abs(it[0] - target[0]) + abs(it[1] - target[1]);

            if(dist <= it[2]){
                if(mindist > dist){
                    mindist = dist;
                    ans = index;
                }
            }
            index++;
        }
        return ans;
        
    }
};