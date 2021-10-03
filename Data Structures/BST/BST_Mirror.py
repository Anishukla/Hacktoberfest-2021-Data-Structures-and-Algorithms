class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
def mirrorTree(root):
    l = []
    l.append(root)

    while len(l):
        i = l[0]
        l.pop(0)
        i.left, i.right = i.right, i.left
        if i.left:
            l.append(i.left)
        if i.right:
            l.append(i.right)
def PreOrder(node):
    if node == None:
        return
    print(node.data, end = " ")
    PreOrder(node.left)
    
    PreOrder(node.right)
    

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)
mirrorTree(root)
PreOrder(root)

# Time complexity - O(n)
# Code contributed by Srinija DHarani
