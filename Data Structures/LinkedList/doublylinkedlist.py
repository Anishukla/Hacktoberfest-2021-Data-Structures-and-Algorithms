class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class doubly_linked_list:

    def __init__(self):
        self.head = None

    # add elements into the linked list	
    def AddElement(self, new_value):
        new_node = Node(new_value)
        new_node.next = self.head
        if self.head is not None:
            self.head.prev = new_node
        self.head = new_node
    # AddLasting to the end
    def AddLast(self, new_value):
    
      new_node = Node(new_value)
      new_node.next = None
      if self.head is None:
         new_node.prev = None
         self.head = new_node
         return
      last = self.head
      while (last.next is not None):
         last = last.next
      last.next = new_node
      new_node.prev = last
      return
    
    def RemoveElement(self, remove_key):
        head = self.head
        if (head is not None):
            if (head.data == remove_key):
                self.head = head.next
                head = None
                return

        while (head is not None):
            if head.data == remove_key:
                break
            prev = head
            head = head.next
        print("Removed Element is", remove_key)
        if (head == None):
            return
        prev.next = head.next
        head = None

    # count the number of nodes
    def CountNodes(self, node):
        count = 0
        while node:
            count +=1
            node=node.next
        return count
    # search for an element
    def SearchElement(self, search_element):
        current_node = self.head
        while current_node != None:
            if current_node.data == search_element:
                print("Element {} found." .format(search_element))
            current_node = current_node.next

    # display the doubly linked list	
    def DisplayList(self, node):
        while (node is not None):
            print(node.data),
            last = node
            node = node.next

dll = doubly_linked_list()
dll.AddElement(10)
dll.AddLast(50)
dll.AddElement(20)
dll.AddElement(30)
dll.AddLast(60)
dll.DisplayList(dll.head)
dll.RemoveElement(30)
dll.SearchElement(60)

# inserting & removing - O(1), search - O(n)
# Code contributed by Srinija Dharani (GitHub - @srinijadharani)
