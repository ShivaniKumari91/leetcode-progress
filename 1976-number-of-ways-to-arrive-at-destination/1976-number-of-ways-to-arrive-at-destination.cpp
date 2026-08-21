class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        // Build adjacency list
        for(auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> way(n, 0);

        dist[0] = 0;
        way[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            long long dis = it.first;
            int node = it.second;

            for(auto it : adj[node]) {

                int adjnode = it.first;
                int wt = it.second;

                // Found a shorter path
                if(dis + wt < dist[adjnode]) {

                    dist[adjnode] = dis + wt;

                    // Number of ways to reach adjnode
                    // is same as number of ways to reach node
                    way[adjnode] = way[node];

                    pq.push({dist[adjnode], adjnode});
                }

                // Found another shortest path
                else if(dis + wt == dist[adjnode]) {

                    way[adjnode] =
                        (way[adjnode] + way[node]) % MOD;
                }
            }
        }

        return way[n-1];
    }
};