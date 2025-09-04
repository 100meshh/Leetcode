class Solution {
public:
    void backtrack(string &digits, int index, vector<string> &mapping, string &current, vector<string> &ans) {
        if(index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for(char c : letters) {
            current.push_back(c);                // choose
            backtrack(digits, index + 1, mapping, current, ans); // explore
            current.pop_back();                  // un-choose
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};


        vector<string> ans;
        vector<string> mapping = {
            "",    "",    "abc",  "def", 
            "ghi", "jkl", "mno",  "pqrs", 
            "tuv", "wxyz"
        };

        string current = "";
        backtrack(digits, 0, mapping, current, ans);
        return ans;
    }
};