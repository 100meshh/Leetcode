class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num : nums) {
            if (num < k) return -1; // can't increase any value
        }

        unordered_set<int> greaterThanK;
        for (int num : nums) {
            if (num > k) greaterThanK.insert(num);
        }

        return greaterThanK.size();
    }

};