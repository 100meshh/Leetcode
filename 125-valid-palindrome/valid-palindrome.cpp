class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
         // Step 1: Extract only alphanumeric characters and convert to lowercase
        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
                ans += tolower(s[i]);  // Convert uppercase to lowercase correctly
            }
        }
        
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