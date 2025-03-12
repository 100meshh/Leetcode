class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0; // Set to 0 and continue to handle carry
        }
        // If we exit the loop, it means all digits were 9, so we need an extra digit
        digits.insert(digits.begin(), 1);
        return digits;
    }


};