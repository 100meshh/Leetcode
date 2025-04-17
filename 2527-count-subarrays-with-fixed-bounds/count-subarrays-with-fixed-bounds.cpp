class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;
        deque<int> dq;
        int lastInvalid = -1, lastMin = -1, lastMax = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                // Reset if number is out of valid range
                lastInvalid = i;
                lastMin = -1;
                lastMax = -1;
            }
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;

            int validStart = min(lastMin, lastMax);
            if (validStart > lastInvalid)
                count += validStart - lastInvalid;
        }

        return count;
    }
};