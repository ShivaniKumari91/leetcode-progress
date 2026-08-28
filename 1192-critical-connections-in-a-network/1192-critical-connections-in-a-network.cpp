class Solution {
private:
    int timer = 1;
private:
    void dfs(int node,int parent,vector<int> adj[],vector<int> &vis,int low[],int tin[],vector<vector<int>> &bridges){
        vis[node] = 1;
        low[node] = timer;
        tin[node] = timer;
        timer++;

        for(auto it: adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,adj,vis,low,tin,bridges);
                low[node] = min (low[node],low[it]);

                if(low[it] > tin[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int low[n];
        int tin[n];
        vector<int> vis(n,0);
        vector<vector<int>> bridges;
        dfs(0,-1,adj,vis,low,tin,bridges);
        return bridges;
        
    }
};