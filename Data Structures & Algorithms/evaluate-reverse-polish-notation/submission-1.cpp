class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        int ans = 0;
        for(auto &i : tokens)
        {
            if(i != "+" && i != "-" && i != "*" && i != "/")
            {
                st.push(stoi(i));
            }
            else
            {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(i=="+") ans = b + a;
            else if(i=="-") ans = b - a;
            else if(i=="*") ans = b * a;
            else ans = b/a;
            //b = ans;
            st.push(ans);
            }
        }
        return st.top();
    }
};
