class Solution {
public:
    bool is_nondec(vector<int>&temp){
        if (temp.size() < 2) return false;
        for(int i=1;i<temp.size();i++){
            if(temp[i-1]>temp[i])return false;
        }
        return true;
    }
    void helper(vector<int>& nums,int index,int n,vector<int>&temp,vector<vector<int>>&ans){
         if (index == n) {
            if (is_nondec(temp)) {
                ans.push_back(temp);
            }
            return;
        }
        //pick
        temp.push_back(nums[index]);
        helper(nums,index+1,n,temp,ans);
        temp.pop_back();
        //not pick
        helper(nums,index+1,n,temp,ans);


    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        helper(nums,0,n,temp,ans);
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};