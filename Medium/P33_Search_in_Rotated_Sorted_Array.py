def search1(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    res = -1
    for i in range(len(nums)):
        if nums[i] == target:
            res = i
    return res

def search(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    l, r = 0, len(nums) - 1
    
    while l <= r:
        m = (l + r)//2
        if nums[m] == target:
            return m
        if nums[l] <= nums[m]:
            if target > nums[m] or target < nums[l]: 
                l = m + 1
            else:
                r = m - 1
        else:
            if target < nums[m] or target > nums[r]:
                r = m - 1
            else:
                l = m + 1
    return -1   
        
def main():
    nums = [4,5,6,7,8,1,2,3]
    target = 8
    print(search(nums, target))

if __name__ == '__main__':
    main()