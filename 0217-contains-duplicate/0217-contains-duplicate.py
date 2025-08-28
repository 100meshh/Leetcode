class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort();
        length = len(nums)
        for i in range(1,length):
            if nums[i-1]==nums[i]: 
                return True
        return False
        