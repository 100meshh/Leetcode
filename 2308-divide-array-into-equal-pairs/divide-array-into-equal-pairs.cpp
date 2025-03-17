class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(); 
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]==nums[j])
                {
                nums[i]=-1;
                nums[j]=-1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=-1)
            return false;
        }
        return true;
    }
};