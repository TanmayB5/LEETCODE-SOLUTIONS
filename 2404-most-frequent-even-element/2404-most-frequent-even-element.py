class Solution(object):
    def mostFrequentEven(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mp = {}
        ans = float('inf')
        cnt = 0

        for n in nums:
            if n%2 == 0:
                mp[n] = mp.get(n,0) + 1

        if not mp:
            return -1

        for x in mp:
            if mp[x] > cnt or (cnt== mp[x] and x<ans) :
                cnt = mp[x] 
                ans = x
        
        return ans
            

