class Solution {
   public:
    vector<vector<int>> ans;
vector<int> temp;
    set<int> st;
    void solve(vector<int>& nums, vector<int> temp) {
        int n = nums.size();
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
             if(st.find(nums[i])==st.end())
             {
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums,temp);
                temp.pop_back();
                st.erase(nums[i]);
             }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        solve(nums,temp);
        return ans;
    }
};
