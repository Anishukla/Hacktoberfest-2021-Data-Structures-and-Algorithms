if __name__ == '__main__':
    N = int(input())
    empty = []
    conv = []

    for i in range(N):
        x = input().split()
        empty.append(x)

    for i in range(len(empty)):
        if empty[i][0] == 'insert':
            x = int(empty[i][1])
            y = int(empty[i][2])
            conv.insert(x,y)
        elif empty[i][0] == 'print':
            print(conv)
        elif empty[i][0] == 'remove':
            conv.remove(int(empty[i][1]))
        elif empty[i][0] == 'append':
            conv.append(int(empty[i][1]))
        elif empty[i][0] == 'sort':
            conv.sort()
        elif empty[i][0] == 'pop':
            conv.pop()
        elif empty[i][0] == 'reverse':
            conv.reverse()
