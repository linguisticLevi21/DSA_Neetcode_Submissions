#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
// int t[46];
// int solve(int i)
// {
//     if(i<=2) return i;
//     if(t[i]!=-1) return t[i];
//     return t[i] = solve(i-1) + solve(i-2);
// }
    int climbStairs(int n) {
       int t[46];
       t[0] = 0;
       t[1] = 1;
       t[2] = 2;

       for(int i = 3 ; i <= n ; i++)
       {
           t[i] = t[i-1] + t[i-2];
       }
       return t[n];
    }
};
