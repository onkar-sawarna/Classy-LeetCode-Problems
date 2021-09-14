class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if(n == 0)return -1;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            if(pq.size()<k)
                pq.push(-1*nums[i]);
            else if(-1*pq.top() < nums[i]){
                pq.pop();
                pq.push(-1*nums[i]);
            }
        }
        int ans =  -1*pq.top();
        return ans;
    }
};