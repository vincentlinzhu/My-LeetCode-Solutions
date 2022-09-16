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
    res = -1
    l, r = 0, len(nums) - 1
    
    while l <= r:
        m = (l + r)/2
        if nums[m] == target:
            res = m
        elif nums[m] > target:
            l = m + 1
        elif nums[m] < target:
            r = m - 1
    return res   
        
def main():
    nums = [4,5,6,7,0,1,2]
    target = 0
    print(search(nums, target))

if __name__ == '__main__':
    main()