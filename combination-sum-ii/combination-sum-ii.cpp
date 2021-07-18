class Solution {
public:
    void helper(vector<int>& c, int tar,vector<vector<int>>& a,vector<int>& contri,int i)
    {   int n=c.size();
        //base cases
       
        
            if(tar == 0){
             a.push_back(contri);
            return;
        }
         if(i==n ){
            return;
        }if(tar < 0){
            return;
        }
        if(tar - c[i] < 0){
            return;
        }
        
        contri.push_back(c[i]);
        helper(c,tar-c[i],a,contri,i+1);
        contri.pop_back();
        int j;
        int prev = c[i];
        for(j=i;j<n and c[j]==prev;j++);
        helper(c,tar,a,contri,j);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> contri;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,ans,contri,0);
        return ans;
    }
};