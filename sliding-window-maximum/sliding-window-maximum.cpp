class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i;
        int n=nums.size();
        deque<int> q(k);
        vector<int> ans;
        if (n < k) {
	    return ans;
        }
        //Process first k elements
        for(i=0;i<k;i++){
            while(!q.empty() and nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
        }
         ans.push_back(nums[q.front()]);
        //The remaining elements are processed here
        for(i=k;i<n;i++){
            
            //if window size exceeds k then pop from front
            if(!q.empty() and q.front()<=(i-k))
                q.pop_front();
            while(!q.empty() and nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};