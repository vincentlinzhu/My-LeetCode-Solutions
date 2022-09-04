def productExceptSelf1(nums):
    """
    :type nums: List[int]
    :rtype: List[int]
    """
    product = 0
    res = []
    for i in range(len(nums)):
        x = nums.pop(i)
        product = nums[0]
        for j in range(1, len(nums)):
            product *= nums[j]
        res.append(product)
        nums.insert(i, x)
    return res

def productExceptSelf(nums):
    """
    :type nums: List[int]
    :rtype: List[int]
    """
    res = [1] * (len(nums))
    prefix = 1
    postfix = 1
    for i in range(len(nums)):
        res[i] = prefix
        prefix *= nums[i]
    for i in range(len(nums) - 1, -1, -1):
        res[i] *= postfix
        postfix *= nums[i]
    return res
    

def main():
    nums = [-1,1,0,-3,3]
    print(productExceptSelf(nums))

if __name__ == '__main__':
    main()