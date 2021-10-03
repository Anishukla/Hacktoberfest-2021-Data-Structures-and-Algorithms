def heapify(arr, n, i):
   largest = i
   l = 2 * i + 1 
   r = 2 * i + 2 
   if l < n and arr[i] < arr[l]:
      largest = l
   if r < n and arr[largest] < arr[r]:
      largest = r
   if largest != i:
      arr[i],arr[largest] = arr[largest],arr[i]
      heapify(arr, n, largest)
# heap sort implementation
def heapSort(arr):
   n = len(arr)
   for i in range(n, -1, -1):
      heapify(arr, n, i)
   for i in range(n-1, 0, -1):
      arr[i], arr[0] = arr[0], arr[i]
      heapify(arr, i, 0)
arr = [6, 4, 7, 1, 9, -2]
heapSort(arr)
for i in range(len(arr)):
   print (arr[i],end=" ")
    
# Time complexity - O(n logn)
# Code contributed by Srinija DHarani
