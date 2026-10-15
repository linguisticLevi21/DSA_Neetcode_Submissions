class Solution {
   public:
    vector<string> ans;
    string temp;
    unordered_map<char, string> mp;
    void solve(string digits, int i) {
        if (i == digits.size()) {
            ans.push_back(temp);
            return;
        }
        for (char c : mp[digits[i]]) {
            temp.push_back(c);
            solve(digits, i + 1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        solve(digits, 0);
        return ans;
    }
};
