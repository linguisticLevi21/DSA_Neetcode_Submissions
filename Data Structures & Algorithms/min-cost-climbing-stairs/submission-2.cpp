#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int t[102];
int solve(vector<int> &cost,int i)
{
  int n = cost.size();
  if(i>=n) return 0;
  if(t[i]!=-1) return t[i];
  int s1 = 0;
  int s2 = 0;
  s1 = cost[i] + min(solve(cost , i+1),solve(cost , i+2));
  //s2 = min(solve(cost , i+1),solve(cost , i+2));
  return t[i] = s1;
}
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t,-1,sizeof(t));
        return min(solve(cost,0),solve(cost,1));
    }
};
