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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);
        if (root == NULL) return result;
        while(!st.empty()){
            TreeNode* cur = st.top();
            result.push_back(cur->val);
            st.pop();
            if(cur->left != nullptr)st.push(cur->left);
            if(cur->right != nullptr)st.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};