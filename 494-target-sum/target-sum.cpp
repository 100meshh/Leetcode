class Solution {
public:
    int countWays(vector<int>& nums, int index, int sum, int target) {
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }
        
        // Try adding and subtracting the current number
        return countWays(nums, index + 1, sum + nums[index], target) +
               countWays(nums, index + 1, sum - nums[index], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countWays(nums, 0, 0, target);
    }
};