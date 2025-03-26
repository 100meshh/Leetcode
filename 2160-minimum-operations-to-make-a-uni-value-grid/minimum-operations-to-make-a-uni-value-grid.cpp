class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>nums;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                nums.push_back(grid[i][j]);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
        if ((nums[i] - nums[0]) % x != 0) {
        return -1; // Not possible
            }
        }
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int operations = 0;

        for (int i = 0; i < nums.size(); i++) {
        operations += abs(nums[i] - median) / x;
        }
        return operations;

    }
};