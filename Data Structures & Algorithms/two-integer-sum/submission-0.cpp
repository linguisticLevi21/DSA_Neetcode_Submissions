class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++)
        {
            int present = nums[i];
            int need = target - nums[i];
            if(mp.find(need)!=mp.end())
            {
                return {mp[need],i};
            }
            mp[present] = i;
        }
        return {-1,-1};
    }
};
