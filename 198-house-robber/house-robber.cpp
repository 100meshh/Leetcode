class Solution {
public:
// int f(int ind,vector<int>&nums,vector<int>&dp){
//     dp[0]=0;
//     int neg=0;
    // if(ind==0) return nums[0];
    // if(ind<0) return 0;
    // for(int i=1;i<n;i++){
    // int take=nums[ind]; if(ind>1) take+=dp[ind-2];
    // int notTake=0+dp[ind-1];
    // dp[ind]=max(take,notTake);
    // }
// }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int ind=1;ind<n;ind++){
        int take=nums[ind];
        if(ind>1) take+=prev2;
        int notTake=0+prev;
        int curI=max(take,notTake);
        prev2=prev;
        prev=curI;
        }
        return prev;
    }
};