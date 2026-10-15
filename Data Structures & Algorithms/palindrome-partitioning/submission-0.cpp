class Solution {
public:
    vector<vector<string>> ans;
    vector<string> pal;

    bool check(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string s, int i) {
        if (i >= s.size()) {
            ans.push_back(pal);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            string temp = s.substr(i, j - i + 1);

            if (check(temp)) {
                pal.push_back(temp);
                solve(s, j + 1);
                pal.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return ans;
    }
};