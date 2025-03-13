class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=1;
        int ans=INT_MIN;
        if(nums.size()==1)
        return 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]<nums[i])
            {
            count++;
            ans=max(ans,count);
            }
            else {
            ans=max(ans,count);
            count=1;
            }

        }
        return ans;
    }
};