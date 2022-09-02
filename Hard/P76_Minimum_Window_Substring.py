from turtle import begin_fill


def minWindow1(s, t):
    """
    :type s: str
    :type t: str
    :rtype: str
    """
    prev_next = 0
    result = ''
    orig_t = t
    next_marker = 0
    min_len = len(s)
    count = 0
    res = []
    indexes = []
    for i in range(len(s)):
        if t[0] in res:
            t = res[0]
        # Find Start
        if s[i] in orig_t:
            res.append(s[i])
            indexes.append(i)
            t = t.replace(s[i], '', 1)
        # After Start
        else:
            res.append(s[i])
        count += 1
        # if len(res) == len(orig_t):
        if len(t) == 0:
            if count < min_len:
                min_len = count
                result = ''.join(res)
            # first_marker = i - count
            next_marker = indexes[1]
            count = count - next_marker
            t = res[0]
            # t = orig_t
            del res[0:next_marker]
            #     for j in range(len(indexes)):
            #         indexes[j] -= next_marker
            #     time += 1
            for j in range(len(indexes)):
                indexes[j] -= (next_marker + prev_next)
            indexes.pop(0)
            indexes[0] = 0
            prev_next = next_marker
            
    if len(res) < min_len:
        min_len = len(res)
        result = ''.join(res)
    return result
       
def minWindow(s, t):
    if t == "":
        return ""
    window = {}
    countT = {}
    for i in range (len(t)):
        countT[t[i]] = countT.get(t[i],0) + 1
    
    have = 0
    need = len(countT)
    res = [-1, -1]
    resLen = float("infinity")
    l = 0
    for r in range(len(s)):
        c = s[r]
        window[c] = 1 + window.get(c, 0)

        if c in countT and window[c] == countT[c]:
            have += 1
        
        while have == need:
            if (r - l + 1) < resLen:
                res = [l, r]
                resLen = r - l + 1
            window[s[l]] -= 1
            if s[l] in countT and window[s[l]] < countT[s[l]]:
                have -= 1
            l += 1
    l = res[0]
    r = res[1]
    if resLen != float("infinity"):
        return s[l:r+1]
    else:
        return ""
        
def main():
    s = "a"
    t = "b"
    print(minWindow(s, t))

if __name__ == '__main__':
    main()