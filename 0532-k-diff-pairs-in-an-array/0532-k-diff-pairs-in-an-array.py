class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        if k==0:
            mp = {}
            ans = 0

            for n in nums:
                mp[n] = mp.get(n,0) + 1
        
            for v in mp.values():
                if v>1:
                    ans +=1
            return ans


        temp = set(nums)
        ans = 0
        
        for n in temp:
            x = n-k
            if x in temp and x!=n:
                ans += 1
        return ans



