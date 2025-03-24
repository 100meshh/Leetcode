class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both the greed factors and the cookie sizes.
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0; // Pointer for children
        int j = 0; // Pointer for cookies
        
        // While there are still children and cookies left.
        while (i < g.size() && j < s.size()) {
            // If the current cookie can satisfy the child
            if (s[j] >= g[i]) {
                i++;  // The child is content, move to the next child.
            }
            // Move to the next cookie in either case.
            j++;
        }
        
        // 'i' now represents the number of children that have been content.
        return i;
    }
};
