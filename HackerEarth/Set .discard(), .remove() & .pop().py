n = int(input())
s = set(map(int, input().split()))
N = int(input())
lists = []

for i in range(N):
    x = input().split()
    lists.append(x)

for i in range(N):
    if lists[i][0] == 'pop':
        if len(s) == 0:
            continue
        else:
            s.pop()

    if lists[i][0] == 'remove':
        x = lists[i][1]
        if int(x) in s:
            s.remove(int(x))
        else:
            continue

    if lists[i][0] == 'discard':
        x = lists[i][1]
        if int(x) in s:
            s.discard(int(x))
        else:
            continue
print(sum(s))
