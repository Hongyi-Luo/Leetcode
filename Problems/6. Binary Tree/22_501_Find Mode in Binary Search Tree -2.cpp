class Solution {
private:
    int maxCount = 0; // 最大频率
    int count = 0; // 统计频率
    TreeNode* pre = NULL;
    vector<int> result;
    
    
    void searchBST(TreeNode* cur){
        if (cur == NULL) return;
        searchBST(cur->left);
        if(pre == NULL){
            count = 1;
        }
        else if(pre->val == cur->val){
            count++;
        }
        else {
            count = 1;
        }
        pre = cur;
        if(count == maxCount){
            result.push_back(cur->val);
        }
        if(count > maxCount){
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }
        
        searchBST(cur->right);
        return;
    }

public:
    vector<int> findMode(TreeNode* root) {
        
        
        result.clear();

        searchBST(root);
        return result;
    }
};