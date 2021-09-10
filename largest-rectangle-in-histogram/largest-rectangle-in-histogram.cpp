class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> stk;
        int left_smallest[n];
        int right_smallest[n];
        //Compute the left smallest element
        for(int i=0;i<n;i++){
            while(!stk.empty() and heights[stk.top()]>=heights[i])
                stk.pop();
            if(stk.empty())left_smallest[i]=0;
            else
                left_smallest[i]=stk.top()+1;
            stk.push(i);
        }
        //empty the stack to be reused
          while(!stk.empty())stk.pop();
        //Compute the right smallest element
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() and heights[stk.top()]>=heights[i])
                stk.pop();
            if(stk.empty())right_smallest[i]=n-1;
            else
                right_smallest[i]=stk.top()-1;
            stk.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,((right_smallest[i]-left_smallest[i]+1)*heights[i]));
        }
        return maxArea;
    }
};