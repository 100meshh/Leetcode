class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            string num=to_string(i);
            int n=num.size();
            if(n%2) continue;
            int start=0;
            int end=num.size()-1;
            int sum1=0,sum2=0;
            while(start<end)
            {
                sum1+=num[start];
                sum2+=num[end];
                start++;
                end--;
            }
                if(sum1==sum2)
                count++;
        }
        return count;
    }
};