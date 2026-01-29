# class Solution(object):
#     def maxProductDifference(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         nums.sort()
#         return nums[-1] * nums[-2] - nums[0] * nums[1]


import heapq

class Solution(object):
    def maxProductDifference(self, nums):
        # min heap (default)
        min_heap = nums[:]
        heapq.heapify(min_heap)

        min1 = heapq.heappop(min_heap)
        min2 = heapq.heappop(min_heap)

        # max heap using negatives
        max_heap = [-n for n in nums]
        heapq.heapify(max_heap)

        max1 = -heapq.heappop(max_heap)
        max2 = -heapq.heappop(max_heap)

        return (max1 * max2) - (min1 * min2)
