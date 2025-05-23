class Solution {
public:
void parenthesis (int n, int left , int right , vector<string>&ans,string &temp){
    // base case 
    if(left+right==2*n)
    {
        ans.push_back(temp);
        return;
    }

    //left parenthesis
    if(left<n){
        temp.push_back('(');
        parenthesis(n,left+1,right,ans,temp);
        temp.pop_back();
    }
    // right parenthesis
    if(right<left){
        temp.push_back(')');
        parenthesis(n,left,right+1,ans,temp);
        temp.pop_back();
    }

}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        parenthesis(n,0,0,ans,temp);
        return ans;
    }
};