class Solution(object):
    def digitCount(self, num):
        """
        :type num: str
        :rtype: bool
        """
        mp ={}

        for i in num:
            temp = int(i)
            mp[temp] = mp.get(temp,0) + 1

        for i in range(len(num)):
            if mp.get(i,0) != int(num[i]):
                return False
              
        return True