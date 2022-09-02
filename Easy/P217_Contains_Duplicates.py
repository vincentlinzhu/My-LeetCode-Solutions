from operator import truediv


def containsDuplicate1(nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        map = {}
        for num in nums:
            map[num] = 1 + map.get(num, 0)
            if map[num] > 1:
                return True
        return False
    
def containsDuplicate2(nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums.sort()
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                return True
        return False
    
def containsDuplicate(nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        hashset = set()

        for n in nums:
            if n in hashset:
                return True
            hashset.add(n)
        return False
        
def main():
    nums = [1]
    print(containsDuplicate(nums))

if __name__ == '__main__':
    main()