M = input();m = input().split()
N = input();n = input().split()

print("\n".join(sorted(list(set(m) ^ set(n)),key=int)))