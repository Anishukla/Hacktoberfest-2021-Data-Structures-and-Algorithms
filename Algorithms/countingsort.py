# Python program for counting sort, contributed by Gokul S
#Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input. 
#Auxiliary Space Complexity: O(n+k)
  
def countSort(arr): 
  
    # output arr
    output = [0 for i in range(len(arr))] 
  
    # to store count of each char
    count = [0 for i in range(256)] 
  
    # store resulting ans
    ans = ["" for _ in arr] 
  
    # Storing count of each char
    for i in arr: 
        count[ord(i)] += 1
  
    # Change count[i] so that count[i] now contains actual position of this character in output arr
    for i in range(256): 
        count[i] += count[i-1] 
 
    for i in range(len(arr)): 
        output[count[ord(arr[i])]-1] = arr[i] 
        count[ord(arr[i])] -= 1
  
    # Copy the output arr so that arr now contains sorted characters 
    for i in range(len(arr)): 
        ans[i] = output[i] 
    return ans  
  
# Driver
arr = "welcometohacktoberfest"
ans = countSort(arr) 
print("Sorted character array is % s" %("".join(ans)))
