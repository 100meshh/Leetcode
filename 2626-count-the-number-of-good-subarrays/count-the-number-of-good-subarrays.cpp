class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        map<int, int> mp;
        long long ans = 0, pairs = 0;
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {  // ✅ initialize i = 0
            pairs += mp[nums[i]];                // ✅ use current count directly
            mp[nums[i]]++;

            while (pairs >= k) {
                ans += (nums.size() - i);
                mp[nums[l]]--;
                pairs -= mp[nums[l]];            // ✅ subtract new count after decrement
                l++;
            }
        }
        return ans;
    }

};