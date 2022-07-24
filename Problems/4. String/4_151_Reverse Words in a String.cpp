class Solution {
public:
    void reverse(string& s, int start, int end){
        for (int i = start, j = end; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s){
        int slowIndex = 0, fastIndex = 0;
        while(s.size() > 0 && fastIndex<s.size() && s[fastIndex]== ' '){
            fastIndex++;
        }
        for(; fastIndex<s.size(); fastIndex++){
            if(fastIndex -1 >0 && s[fastIndex-1] == s[fastIndex] && s[fastIndex] == ' '){
                continue;
            }
            else{
                s[slowIndex++] = s[fastIndex];
            }
        }
        
        if(s[slowIndex - 1] == ' ' && slowIndex -1 >0){
            s.resize(slowIndex -1);
        }
        else{
            s.resize(slowIndex);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); 
        reverse(s, 0, s.size() - 1);
        for(int i = 0; i < s.size(); i++) {
            int j = i;
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
        return s;
    }
};