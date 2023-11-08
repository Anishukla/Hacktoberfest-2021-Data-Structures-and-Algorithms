# Enter your code from here. Read input from STDIN and print from STDOUT
n = int(input())
X = list(map(int, input().split()))
W = list(map(int, input().split()))

sumX = sum([a*b for a,b in zip(X,W)])
print(round((sumX/sum(W)),1))