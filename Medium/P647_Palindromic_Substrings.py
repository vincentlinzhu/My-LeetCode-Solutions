def countSubstrings(s):
    """
    :type s: str
    :rtype: int
    """
    count = 0
    for i in range(len(s)):
        # odd length palindromes
        count += countPali(s, i, i)
        # even length palindromes
        count += countPali(s, i, i + 1)
        
    return count

def countPali(s, l, r):
    count = 0
    while l >= 0 and r < len(s) and s[l] == s[r]:
        count += 1
        l -= 1
        r += 1
    return count

def main():
    s = "aaa"
    print(countSubstrings(s))

if __name__ == '__main__':
    main()