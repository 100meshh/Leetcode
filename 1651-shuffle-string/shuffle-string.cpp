class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char>ans(s.size());
        string final;
        for(int i=0;i<indices.size();i++)
        {
            ans[indices[i]]=s[i];
        }
        for(int i=0;i<ans.size();i++)
        {
            final+=ans[i];
        }
        return final;
        
    }
};