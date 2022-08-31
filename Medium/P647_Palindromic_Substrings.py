def countSubstrings(s):
    """
    :type s: str
    :rtype: int
    """
    count = 0
    for i in range(len(s)):
        # odd length palindromes
        l, r = i, i
        while l >= 0 and r < len(s) and s[l] == s[r]:
                count += 1
                l -= 1
                r += 1
        # even length palindromes
        l, r = i, i + 1
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