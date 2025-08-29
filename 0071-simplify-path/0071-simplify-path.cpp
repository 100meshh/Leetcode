class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int n=path.size();
        int i=0;
        
        while(i<n){
            while(i<n && path[i]=='/')i++;
            if(i>n)break;
            string dir;
            while(i<n && path[i]!='/'){
                dir+=path[i];
                i++;
            }

            if(dir=="."||dir=="")continue;
            else if(dir==".."){
                if(!st.empty())st.pop();
            }
            else st.push(dir);

        }
            if(st.empty())return "/";
            stack<string>st2;
            while(!st.empty()){
                st2.push(st.top());
                st.pop();
            }
            string result="";
            while(!st2.empty()){
                result+="/" + st2.top();
                st2.pop();
            }
        return result;
    }
};