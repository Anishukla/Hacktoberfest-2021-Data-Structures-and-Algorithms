import random

def sorted(x) -> bool:
	n = len(x)
	for y in range(0,n-1):
		if x[y] > x[y+1]:
			return True
	return False

def bogosort(list) -> list:
	while sorted(list):
		random.shuffle(list)
	return list

print(bogosort([1,4,3,2,5]))