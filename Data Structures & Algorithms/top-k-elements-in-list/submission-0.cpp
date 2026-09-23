class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;
        vector<pair<int,int>> a;
        for(auto &i : mp)
        {
            a.push_back({i.second,i.first});
        }
        sort(a.rbegin(),a.rend());
        vector<int> ans;
        int i = 0;
        while(i<k)
        {
           ans.push_back(a[i].second);
           i++;
        }
        return ans;
    }
};
