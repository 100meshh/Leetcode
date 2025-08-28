class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>=0 && s[i]<=9))
            ans+=tolower(s[i]);
        }
        
        // for(int i=0;i<ans.size();i++)              //use tolower instead
        // {
        //     if(ans[i]>='A' && ans[i]<='Z')
        //     {
        //         ans[i] = ans[i] + ('a' - 'A');
        //     }
        // }
        int start=0;
        int end=ans.size()-1;
        while(start<=end)
        {
            if(ans[start]!=ans[end])
            return false;
            start++;
            end--;
        }
        return true;
        
    }
};