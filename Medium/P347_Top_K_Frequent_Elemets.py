import heapq


def topKFrequent1(nums, k):
    """
    :type nums: List[int]
    :type k: int
    :rtype: List[int]
    """
    freq = {}
    res = []
    for num in nums:
        freq[num] = 1 + freq.get(num, 0)
    temp_arr = freq.items()
    res_arr = sorted(temp_arr, key = lambda x: x[1])
    del res_arr[0:len(res_arr) - k]
    for el in res_arr:
        res.append(el[0])
    return res

# Bucket Sort
def topKFrequent2(nums, k):
    """
    :type nums: List[int]
    :type k: int
    :rtype: List[int]
    """
    count = {}
    freq = [[] for i in range(len(nums) + 1)]
    for n in nums:
        count[n] = 1 + count.get(n, 0)
    for n, c in count.items():
        freq[c].append(n)
    res = []
    for i in range(len(freq) - 1, 0, -1):
        for n in freq[i]:     
            res.append(n)
            if len(res) == k:
                return res          

# Heap (deafaults to minHeap)
def topKFrequent(nums, k):
    """
    :type nums: List[int]
    :type k: int
    :rtype: List[int]
    """
    freq = {}
    for num in nums:
        freq[num] = 1 + freq.get(num, 0)
    heap = []
    heapq.heapify(heap)
    for key in freq:
        heapq.heappush(heap, (-freq[key], key))
        
    res = []
    for i in range(k):
        res.append(heapq.heappop(heap)[1])
    return res

def main():
    nums = [1,1,1,2,2,3]
    k = 2
    print(topKFrequent(nums, k))

if __name__ == '__main__':
    main()