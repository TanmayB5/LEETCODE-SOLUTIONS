class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        ans = ""
        for ch in address:
            if ch == ".":
                ans += "[.]"
            else:
                ans += ch
        return ans