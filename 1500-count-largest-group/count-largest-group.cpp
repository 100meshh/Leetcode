class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> count(37);
        int max_size =0;
        for(int i=1;i<=n;++i){
            max_size = max(max_size, ++count [digsum(i)]);
        }
        int res=0;
        for(int i=0;i<count.size();++i){
            if(count[i]==max_size) res++;
        }
        return res;
    }
    int digsum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
};