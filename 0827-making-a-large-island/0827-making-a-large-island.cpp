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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int row = 0; row<n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};

                for(int ind = 0; ind < 4; ind++){
                    int nrow = row + dr[ind];
                    int ncol = col + dc[ind];

                    if(nrow>=0 && ncol >= 0 && nrow <n && ncol < n){
                        if(grid[nrow][ncol]==1){
                            int nodeno = row * n + col;
                            int adjnodeno = nrow * n + ncol; 
                            ds.unionBySize (nodeno,adjnodeno);
                        }                       
                    }

                }
            }
        }

        int mx = 0;
        for(int row = 0; row<n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                set <int> components;

                for(int ind = 0; ind < 4; ind++){
                    int nrow = row + dr[ind];
                    int ncol = col + dc[ind];

                    if(nrow>=0 && ncol >= 0 && nrow <n && ncol < n){
                        if(grid[nrow][ncol]==1){
                            int adjnode  = nrow * n + ncol;
                            components.insert(ds.findUPar(adjnode));
                        }                       
                    }

                }
                int sizetotal  = 0;
                for(auto it : components){
                    sizetotal += ds.size[it]; 
                }
                mx = max(mx,sizetotal+1);
            }
        }
        for(int cell = 0; cell < n*n; cell++) {
            
            mx = max(mx, ds.size[ds.findUPar(cell)]);
        } 
        return mx;

        
    }
};