class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = 0;
        for(int i = 0; i<nums.size() && i<=length; i++){
            int test = i;
            if (test+nums[i] > length){
                length = test+nums[i];
            }
        }
        if(length>=nums.size()-1)
            return true;
        
        return false;
    }
};