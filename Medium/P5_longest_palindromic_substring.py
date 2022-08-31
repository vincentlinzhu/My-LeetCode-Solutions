def isPalindrome0(s):
    """
    :type s: str
    :rtype: str
    """
    l = 0
    r = len(s) - 1
    res_left = ""
    res_right = ""
    res_temp = ""
    res = ""
    max_len = 0
    while l < r:
        while s[l] != s[r]:
            r -= 1
        while s[l] == s[r]:
            res_left = s[l] + res_left
            res_right = res_right + s[r]
            res_temp = res_left + res_right
            if len(res_temp) > max_len:
                max_len = len(res_temp)
                res = res_temp
            l += 1
            r -= 1
        l += 1
        r = len(s) - 1
    return res

def isPalindrome(s):
    """
    :type s: str
    :rtype: str
    """
    res = ""
    max_len = 0
    for i in range(len(s)):
        # odd length palindromes
        l, r = i, i
        while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > max_len:
                    max_len = r - l + 1
                    res = s[l:r+1]
                l -= 1
                r += 1
        # even length palindromes
        l, r = i, i + 1
        while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > max_len:
                    max_len = r - l + 1
                    res = s[l:r+1]
                l -= 1
                r += 1
    return res

def main():
    s = "babad"
    print(isPalindrome(s))

if __name__ == '__main__':
    main()