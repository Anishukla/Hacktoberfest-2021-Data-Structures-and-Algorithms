// 236: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    TreeNode LCA = null;
    public boolean lowestCommonAncestor_(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null)
            return false;
        
        boolean self = false;
        if(root == p || root == q)
            self = true;
        
        boolean left = lowestCommonAncestor_(root.left, p, q);
        boolean right = lowestCommonAncestor_(root.right, p, q);
        
        if((left && right) || (left && self) || (right && self))
            LCA = root;
        
        return left || right || self;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {        
        lowestCommonAncestor_(root, p, q);
        return LCA;
    }
}
// Time Complexity : O(n)
// Space Complexity : recursive space
