queue = []
while 1:
 print("Enter a number for the following functionalites "+"1 for Push and 2 for Pop")
 choice = input()
  
  
 # Adding elements to the queue
 def Push():
  print("Enter the element you want to push into the queue")
  element= input()
  queue.append(element)
   
 # Removing elements from the queue 
 def Remove():
  print("\nElements dequeued from queue") 
  print(queue.pop(0)) 

 if (choice == "1"):
    Push()
 elif(choice == "2"):
  if(len(queue)==0):
   print("list is empty")
  else: 
   Remove()
  
 print("Initial queue") 
 print(queue) 

 print("\nQueue after removing elements") 
 print(queue)