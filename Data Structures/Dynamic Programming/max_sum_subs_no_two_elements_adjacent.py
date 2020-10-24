# Function to return max sum such that
# no two elements are adjacent
def find_max_sum(arr):
    incl = arr[0]
    excl = 0

    for i in range(1, len(arr)):
        new_excl = max(incl, excl)
        incl = excl + arr[i]
        excl = new_excl
    return max(new_excl, incl)


# Driver program to test above function
arr = [5, 5, 10, 100, 10, 5]
print(find_max_sum(arr))
