def characterReplacement(s, k):
    """
    :type s: str
    :type k: int
    :rtype: int
    """
    max_f = 0
    count = {}
    res = 0
    
    l = 0
    r = 0
    for r in range(len(s)):
        count[s[r]] = 1 + count.get(s[r], 0)
        if count[s[r]] > max_f:
            max_f = count[s[r]]
        if (r - l + 1) - max_f > k:
            count[s[l]] -= 1
            l += 1
            
        res = max(res, r - l + 1)
    return res
    

def characterReplacement1(s, k):
    """
    :type s: str
    :type k: int
    :rtype: int
    """
    original_k = k
    original_s = s
    
    max_len = 1
    temp_len = 1
    marker = 0
    max_arr = [s[0]]
    i = 1
    while i < len(s):
        if s[i] in max_arr:
            max_arr.append(s[i])
            temp_len += 1
            i += 1
        else:
            if k != 0:
                k -= 1
                max_arr.append(max_arr[0])
                temp_len += 1
                i += 1
            else:
                if temp_len > max_len:
                    max_len = temp_len
                temp_len = 1
                marker = s.find(max_arr[0]) + 1
                s = s[marker:]
                del max_arr[:]
                max_arr.append(s[0])
                i = 1
                k = original_k
    if len(s) < len(original_s):
        temp_len += k
    if temp_len > max_len:
        max_len = temp_len
        if max_len > len(original_s):
            max_len = len(original_s)
        
    s = original_s
    k = original_k
    marker = len(original_s)
    del max_arr[:]
    max_arr = [s[len(original_s) - 1]]
    temp_len = 1
    i = len(original_s) - 2
    while i >= 0:
        if s[i] in max_arr:
            max_arr.append(s[i])
            temp_len += 1
            i -= 1
        else:
            if k != 0:
                k -= 1
                max_arr.append(max_arr[0])
                temp_len += 1
                i -= 1
            else:
                if temp_len > max_len:
                    max_len = temp_len
                temp_len = 1
                marker = i
                s = s[:marker + 1]
                del max_arr[:]
                max_arr.append(s[len(s) - 1])
                i = len(s) - 2
                k = original_k
    if len(s) < len(original_s):
        temp_len += k
    if temp_len > max_len:
        max_len = temp_len
        if max_len > len(original_s):
            max_len = len(original_s)
        
    return max_len
        
def main():
    s = "AABABBA"
    s1 = "AABABBBBAB"
    s2 = "ABBB"
    s3 = "ABBBA"
    s4 = "EOEMQLLQTRQDDCOERARHGAAARRBKCCMFTDAQOLOKARBIJBISTGNKBQGKKTALSQNFSABASNOPBMMGDIOETPTDICRBOMBAAHINTFLH"
    # print(characterReplacement1(s4, 7))
    print(characterReplacement(s4, 7))

if __name__ == '__main__':
    main()
