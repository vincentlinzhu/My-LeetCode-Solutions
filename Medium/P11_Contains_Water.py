def maxArea(height):
    """
    :type height: List[int]
    :rtype: int
    """
    l = 0
    r = len(height) - 1
    max_area = 0
    temp_area = 0
    max_height = height[0]
    while l < r:
        max_height = min(height[l],height[r])
        temp_area = max_height * (r - l)
        if temp_area > max_area:
            max_area = temp_area
        if height[l] > height[r]:
            r -= 1
        else:
            l += 1
    return max_area       
        
def main():
    height = [2,3,4,5,18,17,6]
    print(maxArea(height))

if __name__ == '__main__':
    main()