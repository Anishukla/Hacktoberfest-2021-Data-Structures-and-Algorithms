#Binary search Recursive in python
#Code is to find any element in array.
#github id : dhruv1214

#define a function and declare parameters in it.
#check the condition


def binarySearch(A,key,low,high):
    if low > high:
        return False
    else:
        mid = (low + high) // 2
        if key == A[mid]:
            return True
        elif key < A[mid]:
            return binarySearch(A,key,low,high -1)
        else:
            return binarySearch(A,key,mid+1 , high)

A = [16,17,21,57,87,90]
found = binarySearch(A,87,0,5)
print("The elment 87" ,found)
