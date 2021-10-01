import re
N = int(input().strip())
lst=[]
for a0 in range(N):
    firstName,emailID = input().strip().split(' ')
    firstName,emailID = [str(firstName),str(emailID)]
    if re.search('@gmail\.com$',emailID):
        lst.append(firstName)
print(*sorted(lst),sep='\n')
