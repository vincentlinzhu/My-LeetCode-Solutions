def maxSubArray(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    max_res = nums[0]
    temp_sum = nums[0]
    for i in range(1, len(nums)):
        temp_sum = max(temp_sum + nums[i], nums[i])
        if temp_sum > max_res:
            max_res = temp_sum 
    
    return max_res    
        
def main():
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    print(maxSubArray(nums))

if __name__ == '__main__':
    main()