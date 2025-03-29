class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;++i)
        {
            int largest=INT_MIN;
            int smallest=INT_MAX;
            for(int j=i;j<n;j++)
            {
                largest=max(largest,nums[j]);
                smallest=min(smallest,nums[j]);
                // long long p= largest-smallest;
                sum+=(long long)(largest-smallest);
            }
        }
        return sum;
    }
};