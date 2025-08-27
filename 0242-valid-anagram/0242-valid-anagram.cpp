class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        vector<bool>visited(s.size(),0);
        for(int i =0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                if(s[i]==t[j] && visited[j]==0){
                    visited[j]=1;
                    break;
                }
            }
        }
        for(int i=0;i<visited.size();i++){
            if(visited[i]==0)return false;
        }
        return true;
    }
};