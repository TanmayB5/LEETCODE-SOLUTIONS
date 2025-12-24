class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mp = {}
        for i in range(len(nums)) :
            temp = target - nums[i]
            if temp in mp:
                return [i,mp[temp]]
            mp[nums[i]] = i 
        