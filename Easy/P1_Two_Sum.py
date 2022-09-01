def twoSum(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        temp = {}
        for i, n in enumerate(nums):
            diff = target - n
            if diff in temp:
                return [temp[diff], i]
            else:
                temp[nums[i]] = i
        
def main():
    nums = [3,3]
    target = 6
    print(twoSum(nums, target))

if __name__ == '__main__':
    main()