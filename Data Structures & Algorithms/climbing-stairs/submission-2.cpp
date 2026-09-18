#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int t[46];
int solve(int i)
{
    if(i<=2) return i;
    if(t[i]!=-1) return t[i];
    return t[i] = solve(i-1) + solve(i-2);
}
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};
