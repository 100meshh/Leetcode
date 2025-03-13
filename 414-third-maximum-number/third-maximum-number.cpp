class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Changed to long long and initialized with LLONG_MIN to handle INT_MIN in nums
        long long FirstMaximum = LLONG_MIN;
        for(int i = 0; i < nums.size(); i++) {
            FirstMaximum = max(FirstMaximum, (long long)nums[i]); // Typecast to long long
        }
        
        long long SecondMaximum = LLONG_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != FirstMaximum)
                SecondMaximum = max(SecondMaximum, (long long)nums[i]);
        }
        
        long long ThirdMaximum = LLONG_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != FirstMaximum && nums[i] != SecondMaximum)
                ThirdMaximum = max(ThirdMaximum, (long long)nums[i]);
        }
        
        // If ThirdMaximum remains LLONG_MIN, then there are less than three distinct numbers;
        // return FirstMaximum (i.e., the maximum) in that case.
        if(ThirdMaximum == LLONG_MIN)
            return (int)FirstMaximum;
        else
            return (int)ThirdMaximum;
    }

};