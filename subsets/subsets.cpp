class Solution {
public:
    void solve(vector<int>& nums,int idx,vector<int>& contri,vector<vector<int>>& ans){
        //for each recursive call include contri in the answer
        ans.push_back(contri);
        for(int i=idx;i<nums.size();i++){
            contri.push_back(nums[i]);
            solve(nums,i+1,contri,ans);
            contri.pop_back();
        }
        //there is no need of any base condition it will automatically stop
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> contri;
        solve(nums,0,contri,ans);
        return ans;
    }
};