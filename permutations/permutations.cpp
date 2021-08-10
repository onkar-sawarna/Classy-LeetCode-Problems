class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans,int start){
        if(start == nums.size()){
            ans.push_back(nums);
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            helper(nums,ans,start+1);
            swap(nums[start],nums[i]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,ans,0);
        return ans;
    }
};