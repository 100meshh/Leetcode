class Solution {
public:

        // chatgpt












    // Union-Find helper functions.
    int find(vector<int>& parent, int i) {
        return parent[i] == i ? i : parent[i] = find(parent, parent[i]);
    }
    
    void unionn(vector<int>& parent, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if(a != b) {
            parent[b] = a;
        }
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // Step 1: Use Union-Find to compute connected components.
        vector<int> parent(n);
        for (int i = 0; i < n; i++) 
            parent[i] = i;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            unionn(parent, u, v);
        }
        // Compress paths
        for (int i = 0; i < n; i++) {
            parent[i] = find(parent, i);
        }
        
        // Step 2: For each component, determine the forced bitmask.
        // Use unsigned int to avoid overflow when shifting.
        const int B = 31;
        unordered_map<int, unsigned int> compForced; // comp id -> forced bitmask
        for (int i = 0; i < n; i++) {
            int comp = parent[i];
            if (compForced.find(comp) == compForced.end()) {
                compForced[comp] = (1U << B) - 1; // all B bits set
            }
        }
        
        // For each edge, clear bits that are not forced.
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            int w = e[2];
            int comp = parent[u]; // u and v are in the same component.
            for (int b = 0; b < B; b++) {
                if (((w >> b) & 1) == 0) {
                    compForced[comp] &= ~(1U << b);
                }
            }
        }
        
        // Step 3: Answer queries.
        vector<int> ans;
        for (auto& q : queries) {
            int s = q[0], t = q[1];
            if (find(parent, s) != find(parent, t)) {
                ans.push_back(-1);
            } else {
                int comp = find(parent, s);
                // Cast to int; the forced mask is computed as unsigned int.
                ans.push_back(static_cast<int>(compForced[comp]));
            }
        }
        return ans;
    }
};
