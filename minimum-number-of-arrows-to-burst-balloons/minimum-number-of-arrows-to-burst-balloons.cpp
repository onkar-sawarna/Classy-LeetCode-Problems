class Solution {
public:
    //sort according to finishing time
    bool static compare(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        int arrow=1;
        int limit=points[0][1];
        int n = points.size();
        for(int i=1;i<n;i++){
            if(points[i][0]<=limit)
                continue;
            limit=points[i][1];
            arrow++;
        }
        return arrow;
    }
};