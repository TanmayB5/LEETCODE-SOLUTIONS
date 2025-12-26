class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        d = {}

        for i in nums:
            if d.get(i,0) >= 1:
                return True
            else :
                d[i] = d.get(i,0) + 1
        return False
        