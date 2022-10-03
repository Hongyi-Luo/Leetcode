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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        
        if (root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val <key){
            root->right = deleteNode(root->right, key);
        }
        else if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr && root->right != nullptr){
                auto retNode = root->right;
                delete root;
                return retNode;
            }
            else if(root->right == nullptr && root->left != nullptr){
                auto retNode = root->left;
                delete root;
                return retNode;
            }
            else{
                TreeNode* cur = root->right;
                while(cur->left != nullptr){
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
            
        }
        return root;
    }
};