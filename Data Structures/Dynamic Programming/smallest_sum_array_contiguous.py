# Python program to find the smallest sum
# contiguous subarray
import sys

# function to find the smallest sum
# contiguous subarray


def smallestSumSubarr(arr, n):
    # to store the minimum value that is ending
    # up to the current index
    min_ending_here = sys.maxsize
    # to store the minimum value encountered so far
    min_so_far = sys.maxsize

    # traverse the array elements
    for i in range(n):
        # if min_ending_here > 0, then it could not possibly
        # contribute to the minimum sum further
        if (min_ending_here > 0):
            min_ending_here = arr[i]
            start=i

        # else add the value arr[i] to min_ending_here
        else:
            min_ending_here += arr[i]
            end=i

        # update min_so_far
        min_so_far = min(min_so_far, min_ending_here)

    # required smallest sum contiguous subarray value
    return min_so_far


# Driver code
arr = [3, -4, 2, -3, -1, 7, -5]
n = len(arr)
print("Smallest sum: ", smallestSumSubarr(arr, n))
