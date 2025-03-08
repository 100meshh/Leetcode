class Solution {
public:
    double myPow(double x, int n) {
        // Convert n to a long long to handle cases like n = -2147483648 safely.
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return myPowHelper(x, N);
    }
    
    // Helper function that performs the recursion with N as long long.
    double myPowHelper(double x, long long n) {
        if (n == 0) return 1.0;
        // Recursively compute power.
        double half = myPowHelper(x * x, n / 2);
        return (n % 2 == 0) ? half : x * half;
    }


};