n = int(input())
bird = list(map(int, input().strip().split()))[:n]
bird.sort()
red = max(set(bird), key = bird.count)
print(str(red))