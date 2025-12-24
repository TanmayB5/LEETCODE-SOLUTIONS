class Solution(object):
    def convertTemperature(self, celsius):
        """
        :type celsius: float
        :rtype: List[float]
        """
        ans= []
        ans.append(celsius + 273.15)
        ans.append(celsius*1.80 + 32.00)
        return ans
        
