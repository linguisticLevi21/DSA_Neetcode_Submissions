#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int t[38];
    int solve(int i) {
        if (i == 0) return 0;
        if (i == 1 || i == 2) return 1;
        if (t[i] != -1) return t[i];
        return t[i] = solve(i - 1) + solve(i - 2) + solve(i - 3);
    }
    int tribonacci(int n) { 
        memset(t,-1,sizeof(t));
        return solve(n); 
        }
};