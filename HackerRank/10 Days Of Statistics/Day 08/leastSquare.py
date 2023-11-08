# Enter your code here. Read input from STDIN. Print output to STDOUT

xy = [map(int, input().strip().split()) for _ in range(5)]
sX, sY, sX2, sXY = map(sum, zip(*[(x, y, x**2, x * y) for x, y in xy]))

b = (5 * sXY - sX *sY) / (5 * sX2 - sX**2)
a = (sY/5) - b*(sX/5)

print('{:.3f}'.format(a+b * 80))