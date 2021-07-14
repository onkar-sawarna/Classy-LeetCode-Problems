class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=-1;
        int longest_len=0;
        unordered_map<int,int> mpp;
        vector<int> freq(256,-1);
        for(right=0;right<s.size();right++){
            if(freq[s[right]] != -1){
                left = max(left,freq[s[right]]+1);
            }
            freq[s[right]]=right;
            longest_len=max(longest_len,right-left+1);
        }
        return longest_len;
    }
};