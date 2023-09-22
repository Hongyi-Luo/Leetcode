class Solution:
    def jump(self, nums: List[int]) -> int:
        result = 0
        length = nums[0]
        cur = 0
        next = 0
        for i in range(len(nums)-1):
            next = max(i+nums[i], next)
            if (i == cur):
                cur = next
                result+=1
        
        return result