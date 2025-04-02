class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n =nums.size();
        long long result=0;
        long long imax=0,dmax=0;
        for(int k=0;k<n;k++)
        {
            result=max(result,dmax*nums[k]);
            dmax=max(dmax,imax-nums[k]);
            imax=max(imax,(long long)nums[k]);
        }
        return result;
        // int first=INT_MIN;
        // int second=INT_MAX;
        // int third=INT_MIN;
        // long long  ans=0;
        // for(int i=0;i<nums.size()-2;++i)
        // {
        //     first=max(first,nums[i]);
        //     for(int j=i+1;j<nums.size()-1;j++)
        //     {
        //         second=min(second,nums[j]);
        //         for(int k=j+1;k<nums.size();++k)
        //         {
        //             third=max(third,nums[k]);
        //             long long p=first-second;
        //             long long q=p*third;
        //             ans=max(ans,q);
        //             // if(ans<0)
        //             // ans=0;
        //         }
        //     }
        // }
        // return ans;
    }
};