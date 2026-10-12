// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
        
//     }
// };


class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;
set<vector<int>> res;
void solve(vector<int> &nums, int i)
{
    int n = nums.size();
    if(i >= n)
    {
        res.insert(temp);
        return;
    }
    solve(nums,i+1);
    temp.push_back(nums[i]);
    solve(nums,i+1);
    temp.pop_back();
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return vector<vector<int>>(res.begin(),res.end());
    }
};
