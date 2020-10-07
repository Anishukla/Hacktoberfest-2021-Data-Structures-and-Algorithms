def closest_sum_pair(a1, a2, target):
    a1_sorted = sorted(a1)
    a2_sorted = sorted(a2)
    i = 0
    j = len(a2_sorted) - 1
    smallest_diff = abs(a1_sorted[0] + a2_sorted[0] - target)
    print(smallest_diff)
    closest_pair = (a1_sorted[0], a2_sorted[0])
    while i < len(a1_sorted) and j >= 0:
        v1 = a1_sorted[i]
        v2 = a2_sorted[j]
        current_diff = v1 + v2 - target
        if abs(current_diff) < smallest_diff:
            smallest_diff = abs(current_diff)
            closest_pair = (v1, v2)
            print(smallest_diff)

        if current_diff == 0:
            i = i+1
            j = j-1
            return closest_pair
        elif current_diff < 0:
            i = i+1
        else:
            j = j-1
    return closest_pair

"""a1 = [-1, 3, 8, 2, 9, 5]
a2 = [4, 1, 2, 10, 5, 20]
a_target = 24"""

a1 = list(map(int, input().split()))
a2 = list(map(int, input().split()))
a_target = int(input())

closest_sum_pair(a1, a2, a_target)
