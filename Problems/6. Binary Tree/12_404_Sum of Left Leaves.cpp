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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        int midValue = 0;
        int leftValue = 0;
        int rightValue = 0;
        
        if(root->left) leftValue = sumOfLeftLeaves(root->left);
        if(root->right) rightValue = sumOfLeftLeaves(root->right);
        
        if(root->left && root->left->left == NULL && root->left->right == NULL)
            midValue = root->left->val;
        int sum = midValue + leftValue + rightValue;
        
        return sum;
    }
};