/* Submitted by Surya Sidhartha.S (https://github.com/S-Surya) */
/* Question link: (https://leetcode.com/problems/sum-root-to-leaf-numbers/) */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* O(n) solution where is the number of nodes in the tree */

int ans=0;

class Solution {

public:

    /* Helper DFS function to traverse from root to node */
    void dfs(TreeNode* node, int sum){
        if(node){
            /* Temporary sum storage */
            sum=sum*10+node->val;
            /* Leaf node case */
            if(!node->left and !node->right){
                ans+=sum;
            }
            else{
                if(node->left){
                    dfs(node->left,sum);
                }
                if(node->right){
                    dfs(node->right,sum);
                }
            }
        }
    }

    /* Driver function */
    int sumNumbers(TreeNode* root) {
        ans=0;
        dfs(root,0);
        return ans;
    }
};