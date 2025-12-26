class Solution(object):
    def findTheDifference(self, s, t):
        res = 0
        for ch in s + t:
            res ^= ord(ch)
        return chr(res)
