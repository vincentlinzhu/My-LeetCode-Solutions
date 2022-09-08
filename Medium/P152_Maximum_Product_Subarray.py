def maxProduct(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    max_prod = nums[0]
    temp_prod = nums[0]
    neg_count = []
    max_arr = [nums[0]]
    if temp_prod < 0:
        neg_count.append(nums[0])
    for i in range(1, len(nums)):
        if nums[i] < 0:
            neg_count.append(nums[i])
            
        if len(neg_count) % 2 == 0:
            temp_prod = max(temp_prod * nums[i], nums[i])
            if temp_prod == nums[i]:
                max_arr = [nums[i]]
            else:
                max_arr.append(nums[i])
        else:           
            if i == len(nums) - 1 and len(neg_count) != 1:
                if nums[i] < 0:
                    if (temp_prod * nums[i]) / neg_count[0] > (temp_prod * neg_count[0]) / nums[i]:
                        max_arr.append(nums[i])
                        del max_arr[:max_arr.index(neg_count[0])]
                        temp_prod = 1
                        for num in max_arr:
                            temp_prod *= num
                        temp_prod /= neg_count[0]
                        neg_count.pop(0)
                else:
                    # if neg_count[0] < neg_count[-1]:
                    x = temp_prod
                    x_arr = max_arr
                    del x_arr[:x_arr.index(neg_count[0]) + 1]
                    x = 1
                    for num in x_arr:
                        x *= num
                    if nums[i] == 0:
                        nums[i] = 1
                    temp_prod = max(x * nums[i], temp_prod/neg_count[-1])
            else:
                if len(neg_count) != 1:
                    temp_prod *= nums[i]
                    max_arr.append(nums[i])
                
            if len(neg_count) == 1:
                if i == len(nums) - 1:
                    x = temp_prod
                    x_arr = max_arr
                    del x_arr[:x_arr.index(neg_count[0]) + 1]
                    x = 1
                    for num in x_arr:
                        x *= num
                    if nums[i] > 0:
                        temp_prod = max(nums[i], temp_prod)
                    else:
                        temp_prod = max(x * nums[i], temp_prod)
                        
                    if temp_prod == nums[i]:
                        max_arr = [nums[i]]
                    else:
                        max_arr.append(nums[i])
                else:
                    if temp_prod != 0:
                        temp_prod *= nums[i]
                        max_arr.append(nums[i])
                    else:
                        temp_prod = nums[i]
                        max_arr = [nums[i]]

        if temp_prod > max_prod:
            max_prod = temp_prod 
    
    return max_prod    

def maxProduct(nums):
    res = nums[0]
    curMin, curMax = 1, 1
    for n in nums:
        tmp = curMax * n
        curMax = max(n * curMax, n * curMin, n)
        curMin = min(tmp, n * curMin, n)
        res = max(res, curMax)
    return res
       
def main():
    nums = [1,2,-1]
    print(maxProduct(nums))

if __name__ == '__main__':
    main()