class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int len = INT_MIN;
        if(s.empty()) return 0;
        unordered_map<char,int> mp;

        while(j<n)
        {
            mp[s[j]]++;
            while(mp[s[j]]>1)
{

               mp[s[i]]--;
               i++;
}len = max(len,j-i+1);
j++;
            }
        return len;
        }
};
