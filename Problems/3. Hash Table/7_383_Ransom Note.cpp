class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        if(ransomNote.size()>magazine.size())
            return false;
        
        for(int i=0; i<magazine.length();i++){
            record[magazine[i]-'a']++;
        }
        
        for(int i=0; i<ransomNote.length();i++){
            record[ransomNote[i]-'a']--;            
        }
        for (int i = 0;i<26;i++){
            if(record[i]<0){
                return false;
            }
        }        
        return true;
    }
};