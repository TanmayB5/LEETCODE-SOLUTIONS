class Solution(object):
    def shuffle(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: List[int]
        """
        ans = []
        for i in range(n):
            j = n + i
            ans.append(nums[i])
            ans.append(nums[j])

        return ans
        