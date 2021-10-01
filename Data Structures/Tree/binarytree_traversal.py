class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree(object):

    def __init__(self, root):
        self.root = Node(root)
    
    def print_tree(self, traversal_type):
        
        if traversal_type == 1: #preorder
            return self.preorder_print(tree.root, "")
        elif traversal_type == 2: #inorder
            return self.inorder_print(tree.root, "")
        elif traversal_type == 3: #postorder
            return self.postorder_print(tree.root, "")
        else:
            print("invalid")
            return False

    def preorder_print(self, start, traversal):
        # root -> left -> right
        if start:
            traversal += (str(start.value)+ "-")
            traversal = self.preorder_print(start.left, traversal)
            traversal = self.preorder_print(start.right, traversal)
            # these are recursive calls
        return traversal

    def inorder_print(self, start, traversal):
        # left -> root -> right
        if start:
            traversal = self.inorder_print(start.left, traversal)
            traversal += (str(start.value) + "-")
            traversal = self.inorder_print(start.right, traversal)
        return traversal

    def postorder_print(self, start, traversal):
        # left -> right -> root
        if start:
            traversal = self.postorder_print(start.left, traversal)
            traversal = self.postorder_print(start.right, traversal)
            traversal += (str(start.value)+ "-")
        return traversal


#            01
#          /    \
#         2      3
#        / \    / \
#       4   5  6   7

# creating the binary tree
tree = BinaryTree(1)
tree.root.left = Node(2)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(5)
tree.root.right.left = Node(6)
tree.root.right.right = Node(7)

print("""Guide:
Press 1 to traverse the tree in pre-order.
Press 2 to traverse the tree in in-order.
Press 3 to traverse the tree in post-order.""")
n = int(input("\tEnter n to traverse through the tree: "))
if n == 1:
    print("\tPre-order Traversal:", tree.print_tree(1))
    # printing pre order traversal 1 2 4 5 3 6 7
elif n == 2:
    print("\tIn-order Traversal:", tree.print_tree(2))
    # printing in order traversal 4 2 5 1 6 3 7
else:
    print("\tPost-order Traversal:", tree.print_tree(3))
    # printing post order traversal 4 5 2 6 7 3 1 
    
# Time Complexity - O(n)
# Code Contributed by Srinija Dharani (GitHub - @srinijadharani)
