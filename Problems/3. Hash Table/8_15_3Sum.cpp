class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > rst;
        sort(nums.begin(), nums.end());

        for(int i =0; i<nums.size(); i++){
            if(nums[i]>0){
                return rst;
            }
            int pointA, pointB;
            pointA = i+1;
            pointB = nums.size()-1;
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            while(pointB > pointA){
                if((nums[i] + nums[pointA] + nums[pointB])>0){
                    pointB--;
                    while(pointA<pointB && nums[pointB] == nums[pointB+1]){
                        pointB--;
                    }
                }
                else if((nums[i] + nums[pointA] + nums[pointB])<0){
                    pointA++;
                    while(pointA<pointB && nums[pointA] == nums[pointA-1]){
                        pointA++;
                    }
                }
                else{
                    rst.push_back(vector<int>{nums[i],nums[pointA],nums[pointB]});
                    while(pointA<pointB && nums[pointB] == nums[pointB-1]){
                        pointB--;
                    }
                    while(pointA<pointB && nums[pointA] == nums[pointA+1]){
                        pointA++;
                    }
                    pointB--;
                    pointA++;
                }
            }
            
        }
        return rst;
    }
};