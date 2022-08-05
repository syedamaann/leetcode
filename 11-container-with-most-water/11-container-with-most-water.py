class Solution:
    def maxArea(self, height: List[int]) -> int:
        res = 0
        l, r = 0,len(height) - 1
        
        while l < r:
            res = max(res, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            elif height[r] <= height[l]:
                r -= 1
        return res