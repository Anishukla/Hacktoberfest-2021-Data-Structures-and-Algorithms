#HackerRank-Python-Sets
#Difficulty : medium

if __name__ == '__main__':
    n, m = map(int, input().split())
    N = list(map(int, input().split()))
    A = set(map(int, input().split()))
    B = set(map(int, input().split()))

    happiness = 0

    for e in N:
        if e in A:
            happiness += 1
        if e in B:
            happiness -= 1

    print(happiness)

#Author : Hasti Sutaria
