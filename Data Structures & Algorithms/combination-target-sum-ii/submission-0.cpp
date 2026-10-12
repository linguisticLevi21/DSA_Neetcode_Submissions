class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;

void solve(vector<int> &candidates , int i , int target)
{
    int n = candidates.size();
    if(target == 0 )
    {
        ans.push_back(temp);
        return;
    }
    if(i>=n || target<0) return;
    temp.push_back(candidates[i]);
    solve(candidates,i+1,target - candidates[i]);
    temp.pop_back();
    while(i+1<n && candidates[i]==candidates[i+1])
    {
        i++;
    }
    solve(candidates,i+1,target);
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,target);
        return ans;
    }
};
