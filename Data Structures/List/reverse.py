#Reversing a list
OrignalList=[]

try:
	

	while True:
		op=int(input("1-add element in list 2-Reverse List 3-Exit "))

		if op==1:
				ele = int(input("enter elem to enter ")) 
				OrignalList.append(ele)               
				print(OrignalList)
		elif op==2:
			if len(OrignalList) ==0:
				print("List is empty")
			else:
				OrignalList.reverse()
				print(OrignalList)
		elif op==3:
				break
		else:
			print("Wrong input")

except ValueError:
	print("Enter number only ")