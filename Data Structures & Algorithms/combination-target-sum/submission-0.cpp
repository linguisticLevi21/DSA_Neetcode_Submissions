class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;

void solve(vector<int> &nums,int i , int target)
{
    int n = nums.size();
    if(i>=n || target<0) return;

    if(target == 0)
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    solve(nums,i,target - nums[i]);
    temp.pop_back();
    solve(nums,i+1,target);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums,0,target);
        return ans;
    }
};
