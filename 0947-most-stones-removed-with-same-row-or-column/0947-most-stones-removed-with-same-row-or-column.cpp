class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        int n = stones.size();
        for(auto it: stones){
            maxrow = max(it[0],maxrow);
            maxcol = max(it[1],maxcol);

        }
        DisjointSet ds(maxrow + maxcol + 2);
        unordered_map<int,int> stonenodes;

        for(auto it  : stones){
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.unionBySize(noderow,nodecol);
            stonenodes[noderow] = 1;
            stonenodes[nodecol] = 1;
        }
        int cnt = 0;
        for(auto it: stonenodes){
            if(ds.findUPar(it.first) == it.first){
                cnt++;
            }
        }
        return n - cnt;
        
    }
};