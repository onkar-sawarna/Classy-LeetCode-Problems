class Solution {
public:
    void helper(vector<int>& candidates,int target,vector<int>& contri,vector<vector<int>>& ans,int idx){
        if(target == 0){
            ans.push_back(contri);
        }
        for(int i=idx;i<candidates.size();i++){
            if(candidates[i] > target)
            {
                break;
            }
            contri.push_back(candidates[i]);
            helper(candidates,target-candidates[i],contri,ans,i);
            contri.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> contri;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,contri,ans,0);
        return ans;
    }
};