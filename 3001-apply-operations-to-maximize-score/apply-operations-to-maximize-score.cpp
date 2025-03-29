class Solution {
public:
    const int MOD = 1e9 + 7;
    
    // Fast modular exponentiation
    long long modPow(long long base, int exp) {
        long long result = 1;
        base %= MOD;
        while(exp > 0) {
            if(exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
    
    // Function to compute the number of distinct prime factors
    int primescore(int n) {
        int count = 0;
        for (int i = 2; i * i <= n; i++) {
            bool found = false;
            while (n % i == 0) {
                found = true;
                n /= i;
            }
            if(found) count++;
        }
        if(n > 1) count++;
        return count;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> data(n);
        for (int i = 0; i < n; i++) {
            data[i] = primescore(nums[i]);
        }
        
        vector<int> left(n, -1);
        vector<int> right(n, n);
        vector<int> st;
        
        // Compute left boundaries
        for (int i = 0; i < n; i++) {
            while (!st.empty() && data[st.back()] < data[i]) {
                st.pop_back();
            }
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
        
        st.clear();
        // Compute right boundaries
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && data[st.back()] <= data[i]) {
                st.pop_back();
            }
            right[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
        
        // Build a combo vector of pairs: (nums[i], count = (i - left[i]) * (right[i] - i))
        vector<pair<int, long long>> combo;
        combo.reserve(n);
        for (int i = 0; i < n; i++) {
            long long count = (long long)(i - left[i]) * (right[i] - i);
            combo.push_back({nums[i], count});
        }
        
        // Sort in descending order based on the number value
        sort(combo.begin(), combo.end(), [](const pair<int, long long>& a, const pair<int, long long>& b) {
            return a.first > b.first;
        });
        
        long long res = 1;
        // Process each pair until k becomes zero
        for (auto &p : combo) {
            if(k <= 0) break;
            int num = p.first;
            long long count = p.second;
            int use = min((long long)k, count);
            res = (res * modPow(num, use)) % MOD;
            k -= use;
        }
        
        return (int)res;
    }
};
