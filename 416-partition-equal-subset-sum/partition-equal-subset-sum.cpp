class Solution {
public:
vector<vector<int>>dp;
bool subsetSum(vector<int>&nums ,int target,int index,int currsum)
{
    if(currsum==target) return true;
    if(index>=nums.size() || currsum>target) return false;
    if(dp[index][currsum]!=-1) return dp[index][currsum];
    bool include = subsetSum(nums,target,index+1,currsum+nums[index]);
    bool exclude = subsetSum(nums,target,index+1,currsum);
    return dp[index][currsum]=include||exclude;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2==1) return false;    //odd sum
        int target=total/2;
        dp.resize(n+1,vector<int>(target+1,-1));
        return subsetSum(nums,target,0,0);
    }
};