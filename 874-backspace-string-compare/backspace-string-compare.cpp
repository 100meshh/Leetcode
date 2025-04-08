class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        string str1,str2;
        for(int i=0;i<s.size();++i){
            if(s[i]=='#' && st1.empty()) continue;
            if(s[i]=='#' && !st1.empty()){
                st1.pop();
            }
            else{
                st1.push(s[i]);
            }
        }
        for(int i=0;i<t.size();++i){
            if(t[i]=='#' && st2.empty()) continue;
            if(t[i]=='#' && !st2.empty()){
                st2.pop();
            }
            else{
                st2.push(t[i]);
            }
        }
        while(!st1.empty()){
            str1+=st1.top();
            st1.pop();
        }
        while(!st2.empty()){
            str2+=st2.top();
            st2.pop();
        }
        if(str1.size()!=str2.size())
        {
            return false;
        }
        int i=0;
        while(i<str1.size()){
            if(str1[i]!=str2[i])
            return false;
            i++;
        }
        return true;
    }
};