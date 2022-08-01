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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        
        while(!st.empty() || cur!=NULL){
            if (cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur-> right;
            }
        }
        return result;
    }
};