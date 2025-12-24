class Solution(object):
    def countMatches(self, items, ruleKey, ruleValue):
        """
        :type items: List[List[str]]
        :type ruleKey: str
        :type ruleValue: str
        :rtype: int
        """
        
        j = 0
        if ruleKey == "type" :
            j = 0
        elif ruleKey == "color":
            j=1
        else :
            j=2
        ans = 0
        for i in items:
            if i[j] == ruleValue:
                ans +=1
                

        return ans