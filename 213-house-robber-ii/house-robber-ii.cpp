class Solution {
public:
int maximumNonAdj(vector<int>&nums){
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
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(maximumNonAdj(temp1),maximumNonAdj(temp2));
    }
};