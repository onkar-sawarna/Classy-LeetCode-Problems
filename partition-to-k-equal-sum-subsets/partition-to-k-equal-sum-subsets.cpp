class Solution {
public:
    bool solve(vector<int>& nums, int k,int subset_sum,vector<bool>& visited,int index,int curr_sum){
        if(k == 1)
            return true;
        if(curr_sum == subset_sum)
           return solve(nums,k-1,subset_sum,visited,0,0);
        for(int i=index;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                curr_sum=curr_sum+nums[i];
                if(solve(nums,k,subset_sum,visited,i+1,curr_sum))
                    return true;
                curr_sum=curr_sum-nums[i];
                visited[i]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0,subset_sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%k != 0)return false;
        else
            subset_sum=sum/k;
        vector<bool> visited (nums.size(),false);
        int index=0,curr_sum=0;
        return solve(nums,k,subset_sum,visited,index,curr_sum);
    }
};