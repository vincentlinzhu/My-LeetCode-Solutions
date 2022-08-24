def lengthOfLongestSubstring(s):
    """
    :type s: str
    :rtype: int
    """
    max_len = 0
    temp_len = 0
    result_arr = []
    for letter in s:
        if letter not in result_arr:
            result_arr.append(letter)
            temp_len += 1
        else:
            if temp_len > max_len:
                max_len = temp_len
            temp_len -= result_arr.index(letter) + 1
            del result_arr[:result_arr.index(letter) + 1]
            result_arr.append(letter)
            temp_len += 1
    if temp_len > max_len:
        max_len = temp_len
    return max_len

def main():
    s = "dvdf"
    print(lengthOfLongestSubstring(s))

if __name__ == '__main__':
    main()
