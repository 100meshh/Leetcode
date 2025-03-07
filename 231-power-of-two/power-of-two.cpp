class Solution {
public:
    bool isPowerOfTwo(int n) {
         if (n == 1)
        return true;
        // If n is less than 1 or not divisible by 2, it can't be a power of two.
        if (n < 1 || n % 2 != 0)
        return false;
        // Recursively check if n/2 is a power of two.
        return isPowerOfTwo(n / 2);
    }
};