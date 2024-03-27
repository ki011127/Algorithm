class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        a = [0 for i in range(100001)]
        for i in nums:
            if i > 0 and i<100001:
                a[i] = 1
        for i in range(1, len(a)):
            if a[i]==0:
                return i
        return 100001