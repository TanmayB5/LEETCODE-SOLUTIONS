class Solution(object):
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        ans = []

        for num in range(left, right + 1):
            temp = num
            is_valid = True

            while temp > 0:
                digit = temp % 10

                if digit == 0 or num % digit != 0:
                    is_valid = False
                    break

                temp //= 10

            if is_valid:
                ans.append(num)

        return ans