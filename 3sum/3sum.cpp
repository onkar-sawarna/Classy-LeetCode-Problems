class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l,r=n-1;
        vector<vector<int>> result;
        for(int i=0;i<n-2;i++){
            if ((i>0) && (nums[i]==nums[i-1]))
               continue;
            l=i+1;
            r=n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum>0){
                    r--;
                }
                else if(sum<0){
                    l++;
                }
                else{
                    vector<int> ans={nums[i],nums[l],nums[r]};
                    result.push_back(ans);
                    while(l<n-1 and nums[l]==nums[l+1])l++;
                    while(r>0 and nums[r]==nums[r-1])r--;
                    l++;
                    r--;
                }
            }
        }
        return result;
    }
};