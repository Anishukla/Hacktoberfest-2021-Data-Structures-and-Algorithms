def average(array):
    col = set(array)
    n = len(col)
    s = sum(col)
    return (s/n)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)