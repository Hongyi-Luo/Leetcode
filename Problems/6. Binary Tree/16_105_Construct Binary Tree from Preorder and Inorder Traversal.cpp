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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        if (preorder.size() == 1) return root;
        
        int delimiterIndex;
        for(delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++){
            if(inorder[delimiterIndex] == preorder[0]) break;
        }
        
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
        
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+ 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin()+ 1 + leftInorder.size(), preorder.end());
        
        root->left = buildTree(leftPreorder,leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);       
        
        
        return root;        
    }
};