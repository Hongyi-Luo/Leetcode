class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int slow = 0;
        for (int fast = 0; fast <size; fast++){
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow += 1;
            }
        }
        return slow;
    }
};