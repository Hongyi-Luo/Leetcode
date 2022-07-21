class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;
        for(int num1:nums1){
            for(int num2:nums2){
                umap[num1+num2]++;
            }
        }
        int count = 0;
        for(int num3:nums3){
            for(int num4:nums4){
                if(umap.find(0-(num3+num4))!=umap.end()){
                    count += umap[0-(num3+num4)];
                }
            }
        }
        return count;
    }
};