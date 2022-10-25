class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool> &used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for (int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
            if(used[i] == true) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;                        
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        result.clear();
        path.clear();
        sort(nums.begin(),nums.end());
        backtracking(nums, used);
        return result;
    }
};