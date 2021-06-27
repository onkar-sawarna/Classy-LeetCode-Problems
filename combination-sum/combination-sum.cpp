class Solution {
public:
    void helper(vector<int>& c,int tar,vector<int>& contri,vector<vector<int>>& a,int i){
        int n=c.size();
        //base cases
        
        if(i==n ){
            if(tar == 0)
              a.push_back(contri);
            return;
        }
        if(tar <= 0){
            if(tar == 0)
              a.push_back(contri);
            return;
        }
        if(tar - c[i] < 0){
            return;
        }
        //recursive cases
        contri.push_back(c[i]);
        helper(c,tar-c[i],contri,a,i);
        contri.pop_back();
        helper(c,tar,contri,a,i+1); 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> contri;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,contri,ans,0);
        return ans;
    }
};