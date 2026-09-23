class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        // for(int j = 0 ; j < n ; j++)
        // {
            for(auto &i : strs)
            {
                string k = i;
                sort(k.begin(),k.end());
                mp[k].push_back(i);
            }
        
        for(auto &i : mp)
        {
            //vector<int> temp = i.second;
            ans.push_back(i.second);
        }
        return ans;
    }
};
