class Solution {
public:

    int sumSubarrayMins(vector<int>& arr) { 
        int n = arr.size();
        const int mod = 1e9 + 7;
        //psee(previous smaller or equal element)
        vector<int> psee(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
       
        //nse (next smaller element)
        vector<int> nse(n);
        while (!st.empty()) st.pop(); // Clear the stack
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        // Step 3: Compute Sum of Minimums
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];  
            long long right = nse[i] - i;
            total = (total + (right * left * arr[i]) % mod) % mod;
        }
        
        return total;
    }


};