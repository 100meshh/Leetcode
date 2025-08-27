class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
    
    // Store original indices before sorting
    vector<pair<int, int>> numWithIndex;
    for (int i = 0; i < n; i++) {
        numWithIndex.push_back({nums[i], i});
    }

    // Sort based on values
    sort(numWithIndex.begin(), numWithIndex.end());

    int start = 0, end = n - 1;

    while (start < end) {
        int sum = numWithIndex[start].first + numWithIndex[end].first;

        if (sum == target) {
            return {numWithIndex[start].second, numWithIndex[end].second}; // Return original indices
        }
        else if (sum < target) {
            start++;
        } 
        else {
            end--;
        }
    }

    return {}; // Return empty vector if no solution found
}
};