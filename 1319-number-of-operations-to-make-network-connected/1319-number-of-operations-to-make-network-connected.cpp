class Solution {
public:

    vector<int> parent, size;

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // Already connected -> extra edge
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int extraEdges = 0;

        // Process all edges
        for (auto it : connections) {

            int u = it[0];
            int v = it[1];

            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            // Already connected
            if (ulp_u == ulp_v) {
                extraEdges++;
            }
            else {
                unionBySize(u, v);
            }
        }

        // Count components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (findUPar(i) == i)
                components++;
        }

        // Need components - 1 edges
        int requiredEdges = components - 1;

        if (extraEdges >= requiredEdges)
            return requiredEdges;

        return -1;
    }
};