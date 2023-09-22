class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int temp = 0;
        
        for (int i=0; i<nums.size(); i++){
            temp += nums[i];
            
            if (temp>result){
                result = temp;
            }
            
            if (temp <= 0){
                temp =0;           
            }
        }
        return result;
    }
};