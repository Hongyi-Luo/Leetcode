class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char s: s){
            if(st.empty() || s!= st.top()){
                st.push(s);
            }
            else{
                st.pop();
            }
        }
        string result="";
        while (!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};