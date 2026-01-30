class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        arr = [0]*n
        ans = []
        for i in nums:
            arr[i-1] +=1
        
        for j in range(n):
            if arr[j] == 0:
                ans.append(j+1)
        
        return ans
        
