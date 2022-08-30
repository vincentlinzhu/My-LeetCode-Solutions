def isAnagram1(s, t):
    """
    :type s: str
    :rtype: int
    """
    for letter in s:
        if t.index(letter) != -1:
            t = t.replace(letter, '', 1)
            s = s.replace(letter, '', 1)
    if len(s) == 0 and len(t) == 0:
        return True
    else:
        return False
    
def isAnagram2(s, t):
    """
    :type s: str
    :rtype: int
    """    
    if len(s) != len(t):
        return False
    countS, countT = {}, {}
    for i in range(len(s)):
        countS[s[i]] = 1 + countS.get(s[i], 0)
        countT[t[i]] = 1 + countT.get(t[i], 0)
    for c in countS:
        if countS[c] != countT.get(c, 0):
            return False
    return True

def isAnagram3(s, t):
    """
    :type s: str
    :rtype: int
    """ 
    return sorted(s) == sorted(t)

def isAnagram4(s, t):
    """
    :type s: str
    :rtype: int
    """ 
    return Counter(s) == Counter(t)

def main():
    s = "anagram"
    t = "nagaram"
    print(isAnagram2(s, t))

if __name__ == '__main__':
    main()