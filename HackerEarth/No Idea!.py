n, m = input().split()
sc_ar = input().split()
A = set(input().split())
B = set(input().split())

print(sc_ar)

print(sum([(i in A) - (i in B) for i in sc_ar]))