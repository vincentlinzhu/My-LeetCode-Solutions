def maxProfit1(prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_diff = 0
        diff = 0
        for i in range(len(prices) - 1):
            for j in range(i + 1, len(prices)):
                if prices[j] > prices[i]:
                    diff = prices[j] - prices[i]
                    if diff > max_diff:
                        max_diff = diff    
        return max_diff

def maxProfit2(prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_diff = 0
        small = prices[0]
        small_ind = 0
        for i in range(1, len(prices)):
            if prices[i] < small and i > small_ind:
                small = prices[i]
                small_ind = i
            if prices[i] - small > max_diff:
                max_diff = prices[i] - small
        return max_diff

def maxProfit3(prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        l, r = 0, 1
        max_diff = 0
        while r < len(prices):
            if prices[r] < prices[l]:
                l = r
                r = l + 1
            else:
                if (prices[r] - prices[l]) > max_diff:
                    max_diff = prices[r] - prices[l]
                r += 1
        return max_diff
    
def maxProfit(prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        res = 0
        l = 0
        for r in range(1, len(prices)):
            if prices[r] < prices[l]:
                l = r
            res = max(res, prices[r] - prices[l])
        return res
        
def main():
    prices = [7,1,5,3,6,4]
    prices2 = [4,2,10,1,6]
    print(maxProfit(prices))
    print(maxProfit(prices2))

if __name__ == '__main__':
    main()