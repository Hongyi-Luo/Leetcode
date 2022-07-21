class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for (int i = 0, j = size - 1; i<j; i++, j--){
            swap(s[i],s[j]);
        }
    }
};