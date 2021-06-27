class Solution {
public:
    void helper(int n,int k,vector<vector<int>>& ans,vector<int>& contri,int i){
        
        if(k<=0){
            if(k==0)
             ans.push_back(contri);
            return;
        }
        if(i>n){
            return;
        }
        contri.push_back(i);
        helper(n,k-1,ans,contri,i+1);
        contri.pop_back();
        helper(n,k,ans,contri,i+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> contri;
        helper(n,k,ans,contri,1);
        return ans;
    }
};