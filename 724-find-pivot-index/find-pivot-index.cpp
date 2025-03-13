class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum1=0,sum2=0;
        int n=nums.size();
        //sum of the array nums.
        for(int i=0;i<n;i++)
        {
            sum1+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            sum1-=nums[i];
            if(sum1==sum2)
            return i;
            sum2+=nums[i];
            
        }
        return -1;
    }
};