class Solution {
public:

        bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void helper(string &s,int index,int n,vector<string>&temp,vector<vector<string>>&ans){
        if(index==n){
            ans.push_back(temp);
            return;
        }
        //pick
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                helper(s,i+1,n,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        int n=s.size();
        helper(s,0,n,temp,ans);
        return ans;
    }
};