# a Python implementation of the Binary Search Algorithm, with a complexity of O(logn) time.
def binary_search(data, target, low, high):
    """
    Return True if target is found in indicated portion of a Python list.
    The search only considers the portion from data[low] to data[high] inclusive.
    and assumes that the list is already sorted.
    """
    if low > high:
        return False # interval is empty; no match
    else:
        mid = (low + high) // 2
        if target == data[mid]: # found a match
            return True
        elif target < data[mid]:
            # recur on the portion left of the middle
            return binary_search(data, target, low, mid − 1)
    else:
        # recur on the portion right of the middle
        return binary_search(data, target, mid + 1, high)
