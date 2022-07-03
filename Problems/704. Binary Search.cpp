/*
二分法的重点在于确立是左闭右闭还是左闭右开。 对应的while的判断条件是否包含等于，
以及middle是否包含在right和left的更改中。
*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right){
            int middle = (left+right)/2;
            
            if (target == nums[middle]){
                return middle;
            }            
            else if (nums[middle] < target){
                left = middle +1;
                
            }
            else if (nums[middle] > target){
                right = middle -1;
            }
        }
        return -1;
    }
};

