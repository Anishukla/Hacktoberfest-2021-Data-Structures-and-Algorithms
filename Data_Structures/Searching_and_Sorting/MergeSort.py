#Code for Merge Sort in Python
#Rishabh Pathak

def mergeSort(lst):
    if len(lst) > 1:
        mid = len(lst) // 2

        #dividing the list into left and right halves
        left = lst[:mid]
        right = lst[mid:]

        #recursive call for further divisions
        mergeSort(left)
        mergeSort(right)

        #iterators for left and right halves
        i = 0
        j = 0

        #iterator for main list
        k = 0

        while i < len(left) and j < len(right):
            #comparing values from left half with the values from right half and inserting the smaller value in the main list
            if left[i] < right[j]:
                lst[k] = left[i]
                i += 1   #incrementing value of iterator for left half
            else:
                lst[k] = right[j]
                j += 1   #incrementing value of iterator for right half

            k += 1       #incrementing value of iterator for main list

        #for all the remaining values
        while i < len(left):
            lst[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            lst[k] = right[j]
            j += 1
            k += 1

#an example
myList = [5, 7, 6, 1, 9]
mergeSort(myList)
print(myList) 

#Time complexity: O(nlogn)
