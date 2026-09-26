class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int i = 0;
        int j = 0;
        int ans = 0;

        while(j<n)
        {
            mp[s[j]]++;
            while(mp[s[j]]>1)
            {
                mp[s[i]]--;
                //mp.erase(s[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
