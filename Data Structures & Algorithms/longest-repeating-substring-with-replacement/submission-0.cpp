class Solution {
public:
    int characterReplacement(string s, int k) {
     int n = s.size();
     int i = 0;
     int j = 0;
     unordered_map<char,int> mp;
     int ans = 1;
     int maxf = 1;
     while(j<n)
     {
        mp[s[j]]++;
        
        maxf = max(maxf,mp[s[j]]);
        while((j-i+1)-maxf>k)
        {
           // maxf = mp[i];
            mp[s[i]]--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
     }
     return ans;
    }
};
