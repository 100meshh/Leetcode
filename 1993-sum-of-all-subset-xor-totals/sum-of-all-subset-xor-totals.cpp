class Solution {
public:
    int solve(int i,vector<int>&nums,int xorr)
    {
        if(i>=nums.size())
        return xorr;
        return solve(i+1,nums,xorr^nums[i])+solve(i+1,nums,xorr);
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0,nums,0);
    }
};