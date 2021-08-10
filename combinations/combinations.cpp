class Solution {
public:
    void helper(int n,int k,vector<vector<int>>& ans,vector<int>& contri,int idx){
        if(k == 0){
            ans.push_back(contri);
        }
        for(int i=idx;i<=n;i++){
            contri.push_back(i);
            helper(n,k-1,ans,contri,i+1);
            contri.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
     vector<vector<int>> ans;
        vector<int> contri;
        helper(n,k,ans,contri,1);
        return ans;
    }
};