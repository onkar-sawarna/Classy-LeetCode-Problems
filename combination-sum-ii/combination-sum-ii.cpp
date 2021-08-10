class Solution {
public:
    void helper(vector<int>& candidates,int target,vector<int>& contri,vector<vector<int>>& ans,int idx){
        if(target == 0){
            ans.push_back(contri);
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx and candidates[i]==candidates[i-1])continue;
            // NOTE : this condition helps neglecting making identical sets
            //  this is the catch of this question
            if(candidates[i] > target)
            {
                break;
            }
            contri.push_back(candidates[i]);
            helper(candidates,target-candidates[i],contri,ans,i+1);
            contri.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> contri;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,contri,ans,0);
        return ans;
    }
};