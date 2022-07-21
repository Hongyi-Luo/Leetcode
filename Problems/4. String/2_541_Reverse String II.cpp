class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        for (int i = 0; i<size; i += 2*k){
            if(i + k < size){
                reverse(s.begin()+i, s.begin()+i+k);
                continue;
            }
            reverse(s.begin()+i, s.end());
        }
        return s;
    }
};