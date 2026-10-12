class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;
void solve(vector<int> &nums, int i)
{
    int n = nums.size();
    if(i >= n)
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    solve(nums,i+1);
    temp.pop_back();
    while(i+1<n && nums[i]==nums[i+1])
    {
        i+=1;
    }
    solve(nums,i+1);
    //temp.pop_back();
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return ans;
    }
};
