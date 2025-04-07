class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size()==0) return s.size();
        stack<char>st;
        int open=0,close=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                open++;
            }
            else
            {
                if(!st.empty())
                {
                open--;
                st.pop();
                }
                else
                close++;
            }
        }
        int ans=open+close;
        return ans;
        
    }
};