def groupAnagram(strs):
    """
    :type strs: List[str]
    :rtype: List[List[str]]
    """
    map = {}
    for s in strs:
        string = ''.join(sorted(s))
        if string in map:
            # print(type(map[string]))
            map[string].append(s)
        else:
            map[string] = [s]
    # return map.items()
    return map.values()
            
    
    

def main():
    strs = ["eat","tea","tan","ate","nat","bat"]
    print(groupAnagram(strs))

if __name__ == '__main__':
    main()
