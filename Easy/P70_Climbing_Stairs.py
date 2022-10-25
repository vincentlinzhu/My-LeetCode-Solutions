def climbStairs(n):
    if (n == 1):
        return 1
    v = [0] * n
    v[0] = 1
    v[1] = 2
    
    for x in range(n - 2):
        v[x + 2] = v[x + 1] + v[x]

    return v[n - 1]

def main():
    print(climbStairs(5))
    
if __name__ == '__main__':
    main()