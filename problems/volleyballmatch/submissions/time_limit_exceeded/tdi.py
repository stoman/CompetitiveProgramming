import math

def choose(n, k):
    return math.factorial(n) / math.factorial(k) / math.factorial(n-k)

def n_games(a, b):
    # 4 of 5 edge cases
    if a < b:
        a, b = b, a
    if a < 25:
        return 0
    if a == 25 and b > 23:
        return 0
    if a > 25 and a - b != 2:
        return 0
    
    # base case
    if a == 25:
        return choose(24 + b, 24)
        
    # last edge case
    return choose(48, 24) * 2**(b - 24)

if __name__ == '__main__':
    import sys
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    print n_games(a, b) % 1000000007
    