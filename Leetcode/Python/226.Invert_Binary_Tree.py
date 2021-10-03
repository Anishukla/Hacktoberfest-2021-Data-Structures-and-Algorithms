    """
    Solution for Leetcode easy problem 226. Invert Binary Tree.
    
    Time Complexity: O(n) where n is the number of nodes in the binary tree.
    Space Complexity: O(n) where n is the number of nodes in the binary tree.
                      This is because the space used by the stack can become n
                      during the recursion, where n is the number of nodes in
                      the binary tree. This would happen in case of a
                      degenerate binary tree (i.e. essentially a linked list).

    Returns:
        [type]: [description]
    """

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return root
        
        # if root.left == None and root.right == None:
        #     return root
            
        # swap the child nodes
        root.left, root.right = root.right, root.left


        self.invertTree(root.left)
        self.invertTree(root.right)

        return root
