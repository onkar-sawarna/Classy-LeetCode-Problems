class Solution {
public:
    bool palindrome(string& s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void helper(string& s,vector<vector<string>>& ans,vector<string>& current_set,int start){
          int n=s.size();
          if(start == n){
             ans.push_back(current_set);
             return; 
          }
        string prefix_word="";
        for(int i=start;i<n;i++){
            prefix_word+=s[i];
            if(!palindrome(prefix_word,0,prefix_word.size()-1))
                continue; 
            current_set.push_back(prefix_word);
            helper(s,ans,current_set,i+1);
            current_set.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current_set;
        helper(s,ans,current_set,0);
        return ans;
    }
};