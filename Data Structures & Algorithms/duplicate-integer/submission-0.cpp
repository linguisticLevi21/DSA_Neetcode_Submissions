class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int u : nums) mp[u]++;
        int ans = -1;
        for(auto &i : mp)
        {
            int freq = i.second;
            if(freq>1)
            {
                return true;
            }
        }
        return false;
    }
};