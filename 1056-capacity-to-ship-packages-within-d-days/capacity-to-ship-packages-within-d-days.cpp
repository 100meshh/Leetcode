class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start=0;
        int end=0;
        int ans=0;
        for(int i=0;i<weights.size();i++){
        start=max(weights[i],start);
        end+=weights[i];
        }
        while(start<=end){
        int mid=start+(end-start)/2;
        int packages=0, din=0;
        for(int i=0;i<weights.size();i++)
        {
            packages+=weights[i];
            if(packages>mid)
            {
                din++;
                packages=weights[i];
            }
        }
        if(din<days)
        {
            ans=mid;
            end=mid-1;
        }
        else
        start=mid+1;
        }
        return ans;
        
    }
};