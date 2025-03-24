class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; // Edge case

        vector<string> ans(numRows, ""); // Create numRows empty strings
        int i = 0;
        
        while (i < s.length()) {
            // Traverse down
            for (int index = 0; index < numRows && i < s.length(); index++) {
                ans[index] += s[i++];
            }
            // Traverse up
            for (int index = numRows - 2; index > 0 && i < s.length(); index--) {
                ans[index] += s[i++];
            }
        }
        
        string res = "";
        for (string str : ans) {
            res += str; // Concatenate all rows
        }
        return res;
    }
};