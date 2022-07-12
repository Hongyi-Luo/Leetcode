class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int result = INT32_MAX;
        int subRange = 0;
        for (int i =0, j =0; j<nums.size();j++){
            sum += nums[j];
            while(sum >= target){
                subRange = j - i +1;
                result = result < subRange ? result : subRange;
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};