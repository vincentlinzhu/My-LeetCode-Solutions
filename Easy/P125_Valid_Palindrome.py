def isPalindrome1(s):
    """
    :type s: str
    :rtype: bool
    """
    filtered_s = ""
    for i in range(len(s)):
        if s[i].isalnum():
            filtered_s += s[i].lower()
            
    if filtered_s == "":
        return True
    
    l = 0
    r = len(filtered_s) - 1
    for l in range(len(filtered_s)//2):
        if filtered_s[l] != filtered_s[r]:
            return False
        else:
            l += 1
            r -= 1
            
    if l + 1 == r - 1:
        return True
    return True

def isPalindrome2(s):
    """
    :type s: str
    :rtype: bool
    """
    l = 0
    r = len(s) - 1
    while l < r:
        while l < r and not s[l].isalnum():
            l += 1
        while r > l and not s[r].isalnum():
            r -= 1
        if s[l].lower() != s[r].lower():
            return False
        l += 1
        r -= 1
    return True

def main():
    s = "race a car"
    s1 = "A man, a plan, a canal: Panama"
    s2 = ".,"
    print(isPalindrome2(s2))

if __name__ == '__main__':
    main()