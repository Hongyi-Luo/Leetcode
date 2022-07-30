class Solution {
public
    class mycomparison {
    public
        bool operator()(const pairint, int& lhs, const pairint, int& rhs) {
            return lhs.second  rhs.second;
        }
    };    
    
    vectorint topKFrequent(vectorint& nums, int k) {
        unordered_mapint, int map;
        for (int i = 0; inums.size(); i++){
            map[nums[i]]++;
        }
        
        priority_queuepairint, int, vectorpairint, int, mycomparison pri_que;
        
        for(unordered_mapint, intiterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(it);
            if (pri_que.size()  k) {  如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

         找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vectorint result(k);
        for (int i = k - 1; i = 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};