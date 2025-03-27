class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        // Step 1: Count occurrences of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Find the dominant element
        int dominant = -1, totalCount = 0;
        for (auto& [num, count] : freq) {
            if (count * 2 > n) {
                dominant = num;
                totalCount = count;
                break;
            }
        }

        if (dominant == -1) return -1; // No dominant element

        // Step 3: Find the smallest valid index
        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) leftCount++; // Count dominant in left part
            int rightCount = totalCount - leftCount; // Count dominant in right part

            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i; // Found the minimum valid index
            }
        }

        return -1;
    }
};
