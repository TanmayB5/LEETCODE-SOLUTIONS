class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) % 2 != 0:
            return False

        openMin = openMax = 0

        for i in range(len(s)):
            if locked[i] == '1':
                if s[i] == '(':
                    openMin += 1
                    openMax += 1
                else:  # s[i] == ')'
                    openMin -= 1
                    openMax -= 1
            else:  # locked[i] == '0', can be either '(' or ')'
                openMin -= 1
                openMax += 1

            # openMin cannot be negative
            openMin = max(openMin, 0)

            # If openMax goes negative, it's impossible to balance
            if openMax < 0:
                return False

        # At the end, openMin must be 0 for the string to be balanced
        return openMin == 0

        