class Solution {
public:
    #define ll long long
    int MOD=1000000007;
    ll binaryexpo(ll a,ll b){
        ll res =1;
        while(b){
            if(b&1)
            res=(res*a)%MOD;
            a=(a*a)%MOD;
            b/=2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
    return (binaryexpo(4,n/2)*binaryexpo(5,n-n/2))%MOD;    
    }
};