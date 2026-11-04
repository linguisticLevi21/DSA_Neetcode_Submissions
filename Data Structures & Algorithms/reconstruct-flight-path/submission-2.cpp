class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<string> ans;
    void dfs(string src) {
        while (!m[src].empty()) {
            string next = m[src].back();
            m[src].pop_back();
            dfs(next);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        m.clear();
        ans.clear();
        for (auto& k : tickets) {
            m[k[0]].push_back(k[1]);
        }
        for (auto& p : m) {
            sort(p.second.rbegin(), p.second.rend());
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
