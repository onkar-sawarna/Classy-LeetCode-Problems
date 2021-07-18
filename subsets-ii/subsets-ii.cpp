class Solution {
public:
    void recursion(vector<vector<int>>& ans,vector<int>& contri,vector<int>& nums,int i){
        if(i == nums.size()){
            ans.push_back(contri);
            return;
        }
        //Exclude
        int prev = nums[i],id;
        for(id=i;id<nums.size() and nums[id]==prev;id++);
        recursion(ans,contri,nums,id);
        //Include
        
        contri.push_back(nums[i]);
        recursion(ans,contri,nums,i+1);
        contri.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> contri;
        sort(nums.begin(),nums.end());
        recursion(ans,contri,nums,0);
        return ans;
    }
};