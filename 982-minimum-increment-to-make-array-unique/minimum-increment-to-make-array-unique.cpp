class Solution {
public:
int findmax(vector<int>& nums){
    int great=INT_MIN;
    int n=nums.size();
    for(int i=0;i<n;++i){
        great=max(great,nums[i]);
    }
    return great;
}
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int maxelement=findmax(nums);
        vector<int>count(n+maxelement+1,0);

        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        int moves=0;
        for(int i=0;i<count.size();i++){
            if(count[i]<=1) continue;
            int extra=count[i]-1;
            moves+=extra;
            count[i+1]+=extra;
            count[i]-=extra;
        }
        return moves;

    }

};