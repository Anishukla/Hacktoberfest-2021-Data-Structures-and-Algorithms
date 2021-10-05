# By someshvk

class Node:
	# This class helps us to create a single node.
	def __init__(self, data):
		self.data = data
		self.next = None

class Queue:
	# Initialize queue with front and rear as NULL.
	def __init__(self):
		self.front = None
		self.rear = None

	# Check if front and rear are NULL or not (Time Complexity - O(1)).
	def isEmpty(self):
		if self.rear == None and self.front == None:
			return True
		else:
			return False

	# Adding a node to our Queue at the end (Thats how a queue work)(Time Complexity - O(1)).
	def enqueue(self, data):
		if self.rear == None and self.front == None:
			self.front = self.rear = Node(data)
		else:
			newnode = Node(data)
			self.rear.next = newnode
			self.rear = newnode

	# Deleting a node from beginning (First in First out)(Time Complexity - O(1)).
	def dequeue(self):
		if self.isEmpty():
			print("Queue is empty.")
			return None
		elif self.front == self.rear:
			temp = self.front.data
			self.front = self.rear = None
			return temp
		else:
			temp = self.front
			self.front = self.front.next
			temp.next = None
			return temp.data

	# Displays Queue vertically (Easy to understand)(Time Complexity - O(n)).
	def display(self):
		if self.isEmpty():
			print("Queue is empty.")
		else:
			if self.front == self.rear:
				print(self.front.data, " <--- Front, Rear")
			else:
				i = self.front
				print(i.data, " <--- Front")
				i = i.next
				while i.next != None:
					print(i.data)
					i = i.next
				print(self.rear.data, " <--- Rear")

if __name__ == '__main__':
	print("Enter, ")
	print("1->Add element to Queue.")
	print("2->Delete element from Queue.")
	print("3->Check if queue is empty.")
	print("4->Display the Queue.")
	print("5->EXIT.")
	q = Queue()
	while True:
		choice = int(input("Enter your choice: "))
		if choice == 1:
			val = int(input("Enter the item to add: "))
			q.enqueue(val)
		elif choice == 2:
			print(q.dequeue(), " got deleted.")
		elif choice == 3:
			print("Yes.") if q.isEmpty() else print("No.")
		elif choice == 4:
			q.display()
		elif choice == 5:
			print("Bye.")
			break
		else:
			print("Enter a valid input.")