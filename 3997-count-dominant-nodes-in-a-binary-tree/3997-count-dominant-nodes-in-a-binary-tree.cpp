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
class Solution {
public:
    int helper(TreeNode *node,int &count){
        int rside=0,lside=0;
        if(node->right) rside=helper(node->right,count);
        if(node->left) lside=helper(node->left,count);

        if(node->val>=max(lside,rside)) count++;
        return max({node->val,lside,rside});
    }
    int countDominantNodes(TreeNode* root) {
        int count=0;
        helper(root,count);
        return count;
    }
};