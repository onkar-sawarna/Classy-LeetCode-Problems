class Solution {
public:
    bool memoization(unordered_set<string>& dict, string& s, int i, vector<int>& memo)
    {
        if(s.size() == i)
            return true;
        if(memo[i] != -1)
            return memo[i];
        for(int j = s.size()-1; j >= i; j--)
        {
            string sub = s.substr(i, j-i+1);
            if(dict.find(sub) != dict.end() && memoization(dict, s, j+1, memo))
            {
                memo[i] = true;
                return true;
            }
        }
        memo[i] = false;
        return false;        
    }
   bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto& w: wordDict)
            dict.insert(w);
         vector<int> memo(s.size(), -1);
        if(memoization(dict, s, 0, memo))
            return true;
       return false;
   }
};