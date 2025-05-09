class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int start=INT_MIN;
        int end=0;
        int ans=0;
        for(int i=0;i<n;i++){
            start=max(start,nums[i]);
            end+=nums[i];
        }

        while(start<=end){
            int mid=start+(end-start)/2;
            int page=0;
            int count=1;

            for(int i=0;i<n;i++){
                page+=nums[i];
                if(page>mid){
                    count++;
                    page=nums[i];
                }
            }

            if(count<=k){
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
        
    }
};