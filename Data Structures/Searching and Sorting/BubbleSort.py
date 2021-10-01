'''
Name: Ayushi Rawat
GitHub username: ayushi7rawat
Program name: Bubble sort in Python
'''

a = [36, 29, 21, 25, 30, 2, 44]

#repeating loop len(a)(number of elements) number of times
for j in range(len(a)):
    #initially swapped is false
    swapped = False
    i = 0
    
    while i<len(a)-1:
        #comparing the adjacent elements
        
        if a[i]>a[i+1]:
            #swapping
            a[i],a[i+1] = a[i+1],a[i]
            #Changing the value of swapped
            swapped = True
        i = i+1
        
    #if swapped is false then the list is sorted
    #we can stop the loop
    if swapped == False:
        break
        
print (a)