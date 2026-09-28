class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
                a++;
            }
            else 
            {
                b++;
            if (!st.empty() && s[i] == ')' && st.top() == '(')
                st.pop();
            else if (!st.empty() && s[i] == '}' && st.top() == '{')
                st.pop();
            else if (!st.empty() && s[i] == ']' && st.top() == '[')
                st.pop();
                else return false;
            } 
        }
      // if(a==0) return false;
        return st.empty();
    }
};
