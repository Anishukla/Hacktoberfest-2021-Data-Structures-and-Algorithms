# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(input())

for i in range(n):
    s = input()
    print(s[::2], s[1::2])
