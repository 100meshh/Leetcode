class Solution {
public:
    void subSequence(vector<int>& arr,int index,int n,vector<vector<int> > &ans,vector<int>temp)
        {
        if(index==n)
        {
        ans.push_back(temp);
        return;
        }
        // not include
        subSequence(arr,index+1,n,ans,temp);
        // include
        temp.push_back(arr[index]);
        subSequence(arr,index+1,n,ans,temp);

        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int>temp;
        subSequence(nums,0,nums.size(),ans,temp);
        return ans;
    }
};