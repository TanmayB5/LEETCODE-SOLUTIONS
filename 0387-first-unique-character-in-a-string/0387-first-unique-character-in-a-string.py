class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """

        id = -1
        d ={}

        for i in range(len(s)):
            d[s[i]] = d.get(s[i],0) +1
        
        for j in range(len(s)):
            if d[s[j]] == 1:
                return j

        return id