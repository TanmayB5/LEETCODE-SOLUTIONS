class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False
        
        y = str(x)

        for i in range(len(y)/2):
            if(y[i] != y[len(y)-1-i]):
                return False
        
        return True