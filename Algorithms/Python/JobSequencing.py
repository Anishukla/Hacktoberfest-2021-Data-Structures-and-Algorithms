# schedule jobs here
def printjobschedule(array, t):

    m = len(array)

    # sorting jobs
    for j in range(m):
        for q in range(m - 1 - j):
            if array[q][2] < array[q + 1][2]:
                array[q], array[q + 1] = array[q + 1], array[q]
    res = [False] * t

    job = ['-1'] * t

    for q in range(len(array)):
        for q in range(min(t - 1, array[q][1] - 1), -1, -1):
            if res[q] is False:
                res[q] = True
                job[q] = array[q][0]
                break

    # display jobs
    print(job)


array = [['a', 7, 202],
       ['b', 5, 29],
       ['c', 6, 84],
       ['d', 1, 75],
       ['e', 2, 43]]

print("Job sequence that gives the maximum profit - ")
printjobschedule(array, 3)

# Time complexity - O(n^2)
