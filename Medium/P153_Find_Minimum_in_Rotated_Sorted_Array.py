def findMin1(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    res_min = nums[0]
    for num in nums:
        if num < res_min:
            res_min = num
    
    return res_min

def findMin(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    l, r = 0, len(nums) - 1
    res_min = nums[0]
    while l <= r:
        if nums[l] < nums[r]:
            res_min = min(res_min, nums[l])
            break
        m = (l + r)/2
        res_min = min(res_min, nums[m])
        if nums[m] >= nums[l]:
            l = m + 1
        else:
            r = m - 1
    
    return res_min
        
def main():
    nums = [3,4,5,1,2]
    print(findMin(nums))

if __name__ == '__main__':
    main()