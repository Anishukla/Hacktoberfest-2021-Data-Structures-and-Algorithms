# Enter your code here. Read input from STDIN. Print output to STDOUT

avgX, avgY = [float(num) for num in input().split()]

costX = 160 + 40*(avgX + (avgX ** 2))
costY = 128 + 40*(avgY + (avgY ** 2))

print(round(costX,3))
print(round(costY,3))