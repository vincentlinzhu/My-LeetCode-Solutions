def longestConsecutive(nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numSet = set(nums)
        longest = 0
        
        for n in nums:
            if (n - 1) not in numSet:
                length = 1
                while (n + length) in numSet:
                    length += 1
                longest = max(longest, length)
                
        return longest
        
def main():
    nums = [100,4,200,1,3,2]
    print(longestConsecutive(nums))

if __name__ == '__main__':
    main()