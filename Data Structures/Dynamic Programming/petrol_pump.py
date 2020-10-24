# Python program to find circular tour for a track

# A petrol pump has petrol and distance to next petrol pimp
# https://www.youtube.com/watch?v=zcnVaVJkLhY
# https://leetcode.com/problems/gas-station/discuss/805989/Brute-Force-and-One-Pass-oror-Step-by-step-Explanation(with-proof-graph-and-code)-oror-Beginners-Friendly


class PetrolPump:

    # Constructor to create a new node
    def __init__(self, petrol, distance):
        self.petrol = petrol
        self.distance = distance

# The function return starting point if there is a possible
# solution otherwise returns -1


def printTour(arr):

    n = len(arr)
    # Consider first petrol pump as starting point
    start = 0
    end = 1

    curr_petrol = arr[start].petrol - arr[start].distance

    # Run a loop whie all petrol pumps are not visited
    # And we have reached first petrol pump again with 0
    # or more petrol
    while(end != start or curr_petrol < 0):

        # If current amount of petrol pumps are not visited
        # And we have reached first petrol pump again with
        # 0 or more petrol
        while(curr_petrol < 0 and start != end):

            # Remove starting petrol pump. Change start
            curr_petrol -= arr[start].petrol - arr[start].distance
            start = (start + 1) % n

            # If 0 is being considered as start again, then
            # there is no possible solution
            if start == 0:
                return -1

        # Add a petrol pump to current tour
        curr_petrol += arr[end].petrol - arr[end].distance

        end = (end + 1) % n

    return start


# Driver program to test above function
arr = [PetrolPump(6, 4), PetrolPump(3, 6), PetrolPump(7, 3)]
start = printTour(arr)

print("No solution" if start == -1 else "start =", start)

# This code is contributed by Nikhil Kumar Singh(nickzuck_007)
